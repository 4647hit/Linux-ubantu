#pragma once
#include <iostream>
#include "Log.hpp"
#include <strings.h>
#include "Inetaddr.hpp"
#include <cstring>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <functional>
#include "Threadpool.hpp"
enum
{
    SOCKET = 1,
    BIND
};

class Udpserver
{
public:
    using handmessage_t = std::function<void(int fd, std::string buffer, Inetaddr &addr)>;
    Udpserver(uint16_t port, handmessage_t fun) : _port(port), _func(fun), _isrunning(false)
    {
    }
    void InitServer()
    {
        _fd = socket(AF_INET, SOCK_DGRAM, 0);
        if (_fd < 0)
        {
            LOG(INFO, "socket fail")
            exit(SOCKET);
        }

        struct sockaddr_in infor;
        bzero(&infor, sizeof(infor)); // 清空数据
        infor.sin_family = AF_INET;
        // 主机序列转网络序列
        infor.sin_port = htons(_port);
        infor.sin_addr.s_addr = htonl(INADDR_ANY);
        // 绑定
        socklen_t len = (socklen_t)sizeof(infor);
        int count = bind(_fd, (struct sockaddr *)&infor, len);
        if (count < 0)
        {
            LOG(ERROR, "bind fail ...")
            exit(BIND);
        }
        LOG(INFO, "bind success")
    }
    void Start()
    {
        _isrunning = true;
        LOG(INFO, "begin server...")
        //Threadpool<handmessage_t> pool;
        while (1)
        {
            char buffer[1024];
            memset(buffer, 0, sizeof(buffer));
            struct sockaddr_in src;
            socklen_t len = (socklen_t)sizeof(src);
            ssize_t rnum = recvfrom(_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&src, &len);
            if (rnum > 0)
            {
                buffer[1023] = 0;
                Inetaddr addr(&src);
                // buffer
                //LOG(INFO, "receive informaiton success")
                //printf("#[%s:%d]: %s\n", addr.IP().c_str(), addr.Port(), buffer);
                // std::string response = _func(buffer);
                std::string str(buffer);
                _func(_fd,str,addr);
                // if(response.empty())
                // {
                //     response += " There is not this word";
                // }
                // ssize_t snum = sendto(_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&src, len);
            }
        }
        _isrunning = false;
    }
    ~Udpserver()
    {
    }

private:
    int _fd;
    bool _isrunning;
    uint16_t _port;
    // std::string _IP;
    handmessage_t _func;
};