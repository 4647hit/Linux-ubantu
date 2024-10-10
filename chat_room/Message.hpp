#include <iostream>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>
#include <vector>
#include "Inetaddr.hpp"
#include <functional>
#include "Threadpool.hpp"

class Message
{
    // typedef struct sockaddr_in socketaddr_in;
using task_t = std::function<void()>;
public:
    Message()
    {
    }
    void Adduser(Inetaddr addr)
    {
        for (auto e : _list)
        {
            if (e == addr)
            {
                return;
            }
        }
        _list.push_back(addr);
    }
    void Deluser(Inetaddr addr)
    {
        for (auto it = _list.begin(); it != _list.end(); it++)
        {
            if (*it == addr)
            {
                _list.erase(it);
                return;
            }
        }
    }
    void HandRoute(int _sockfd,std::string _message, Inetaddr _addr)
    {
        // 发送给各个终端。
        for (auto e : _list)
        {
            socklen_t len = sizeof(*e.Sock());
            ::sendto(_sockfd,_message.c_str() , _message.size(), 0, (struct sockaddr *)(_addr.Sock()), len);
        }
    }
    void Route(int _sockfd, std::string _messages, Inetaddr _addr)
    {
        Adduser(_addr);

        if (_messages == "Quit")
        {
            Deluser(_addr);
        }
        // 发送给各个终端。
        //  for(auto e:_list)
        //  {
        //      socklen_t len = sizeof(*e.Sock());
        //      ::sendto(_sockfd,_messages.c_str(),_messages.size(),0, (struct sockaddr*)(_addr.Sock()),len);
        //  }
        task_t t = std::bind(&Message::HandRoute,this,_sockfd,_messages,_addr);
        Threadpool<task_t> pool;
        pool.Init_Threadpool();
        pool.Enqueue(t);
        pool.Start();
    }
    ~Message()
    {
    }

private:
    std::vector<Inetaddr> _list;
};