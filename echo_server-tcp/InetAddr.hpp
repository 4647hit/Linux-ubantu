#include <iostream>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>

class Inetaddr
{
private:
    void Init()
    {
        ip = inet_ntoa(peer.sin_addr);
        port = ntohs(peer.sin_port); 
    }
public:
    Inetaddr(struct sockaddr_in _peer):peer(_peer)
    {
        Init();
    }
    std::string Ip()
    {
        return ip;
    }
    int Port()
    {
        return port;
    }
    bool operator==(Inetaddr addr)
    {
        return addr.Port() == port && addr.Ip() == ip;
    }
    ~Inetaddr()
    {
    }
private:
    std::string ip;
    int port;
    struct sockaddr_in peer;
};