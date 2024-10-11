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
#include "pthread.h"
class Message
{
    // typedef struct sockaddr_in socketaddr_in;
using task_t = std::function<void()>;
public:
    bool isExist(Inetaddr addr)
    {
        for(auto it = _list.begin(); it != _list.end(); it++)
        {
            if(*it == addr)
            {
                return true;
            }
        }
        return false;
    }
    Message()
    {
    }
    void Adduser(const Inetaddr& addr)
    {
	    printf("1\n");
        if(!isExist(addr))
        {
            _list.push_back(addr);
            LOG(INFO, "add user success")
        }
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
    void HandRoute(int _sockfd,std::string _message, Inetaddr who)
    {
        pthread_mutex_t lock;
        pthread_mutex_init(&lock,nullptr);
        pthread_mutex_lock(&lock);
        // 发送给各个终端。
        for (auto e = _list.begin(); e != _list.end(); e++)
        {
            std::cout << "["  << e->IP() << " : " << e->Port() << "] is sent: " << _message << std::endl; 
            socklen_t len = sizeof(*(e->Sock()));
            ::sendto(_sockfd,_message.c_str() , _message.size(), 0, (struct sockaddr *)(e->Sock()), len);
        }
        pthread_mutex_unlock(&lock);
        pthread_mutex_destroy(&lock);
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
        Threadpool<task_t>::Getinstance()->Enqueue(t);
    }
    ~Message()
    {
    }
private:
    std::vector<Inetaddr> _list;
};
