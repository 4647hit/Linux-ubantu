#pragma once
#include<iostream>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <cstring>


class Inetaddr
{
private:
    void Init()
    {
        port = ntohs(_src->sin_port);
        ip = inet_ntoa(_src->sin_addr);
        cli.sin_family=AF_INET;
        cli.sin_port=htons(port);
        cli.sin_addr.s_addr=inet_addr(ip.c_str());
        _src=&cli;
    }
public:
    Inetaddr(struct sockaddr_in* src):_src(src)
    {
        Init();
    }
    bool operator==(Inetaddr addr)
    {
        if(addr.IP() == ip && addr.Port() == port)
        {
            return true;
        }
        return false;
    }
    struct sockaddr_in* Sock()
    {
        return _src;
    }
    std::string IP()
    {
        return ip;
    }
    uint16_t Port()
    {
        return port;
    }
    ~Inetaddr()
    {
    }
private:
    struct sockaddr_in* _src;
    struct sockaddr_in cli;
    std::string ip;
    uint16_t port;
};