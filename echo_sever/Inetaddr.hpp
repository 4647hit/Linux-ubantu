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
    }
public:
    Inetaddr(struct sockaddr_in* src):_src(src)
    {
        Init();
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
    std::string ip;
    uint16_t port;
};