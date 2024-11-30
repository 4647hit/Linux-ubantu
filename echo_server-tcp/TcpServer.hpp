#include <iostream>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/wait.h> /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "Log.hpp"
#include <unistd.h>
#include <functional>
#include "InetAddr.hpp"
class TcpServer;
class ThreadDate
{
public:
    ~ThreadDate()
    {
    }
    ThreadDate(int _sockfd, struct sockaddr_in _add, TcpServer *_self) : sockfd(_sockfd), addr(_add), self(_self)
    {
    }

public:
    TcpServer *self;
    int sockfd;
    struct sockaddr_in addr;
};
using task_t = std::function<void *(void *)>;
using fun = std::function<std::string(std::string)>;
class TcpServer
{
    const static int defaultfd = -1;
    const int backlog = 16;

public:
    TcpServer(int port, fun _function) : _port(port), fun_t(_function), _listensockfd(defaultfd), _isrunning(false)
    {
    }
    void Init_Server()
    {
        _listensockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (_listensockfd < 0)
        {
            LOG(FATAL, "socket create failed")
        }
        struct sockaddr_in server;
        bzero(&server, sizeof(server));
        server.sin_port = htons(_port);
        server.sin_addr.s_addr = htonl(INADDR_ANY);
        server.sin_family = AF_INET;
        int n = bind(_listensockfd, (struct sockaddr *)&server, sizeof(server));
        if (n < 0)
        {
            LOG(FATAL, "bind failed")
            exit(1);
        }
        LOG(INFO, "bind success")

        n = ::listen(_listensockfd, backlog);
        if (n < 0)
        {
            LOG(FATAL, "listen failed")
        }
    }
    void Server(int sockfd, struct sockaddr_in &peer)
    {
        Inetaddr addr(peer);
        std::string clientaddr = "[" + addr.Ip() + " : " + std::to_string(addr.Port()) + "]";
        while (true)
        {
            char inbuffer[1024];
            ssize_t n = read(sockfd, inbuffer, sizeof(inbuffer) - 1);
            if (n > 0)
            {
                inbuffer[n] = 0;
                std::cout << clientaddr << inbuffer << std::endl;

                std::string echo_string = "[server echo]# ";
                echo_string += inbuffer;

                write(sockfd, echo_string.c_str(), echo_string.size());
            }
            else if (n == 0)
            {
                // client 退出&&关闭连接了
                LOG(INFO, "%s quit\n", clientaddr.c_str());
                break;
            }
            else
            {
                LOG(ERROR, "read error\n", clientaddr.c_str());
                break;
            }
            sleep(5);
            break;
        }
        // while (true)
        // {
        //     if(CheckClose(sockfd,peer))
        //     {
        //         LOG(INFO,"client close")
        //         ::close(sockfd);
        //         return;
        //     }
        //     ssize_t count = 1024;
        //     std::string result;
        //     while (true)
        //     {
        //         char buffer[1024];
        //         memset(buffer, 0, sizeof(buffer));
        //         count = read(sockfd, buffer, sizeof(buffer) - 1);
        //         if (count > 0)
        //         {
        //             // std::cout << client_infor << buffer << std::endl;
        //             // fflush(stdout);
        //             result += buffer;
        //         }
        //         else if (count == 0)
        //         {
        //             // LOG(INFO, "client close...")
        //             //::close(sockfd);
        //             break;
        //         }
        //         else
        //         {
        //             LOG(ERROR, "read fail")
        //         }
        //     }
        //     std::string Re = fun_t(result);
        //     write(sockfd, Re.c_str(), count);
        // }
    }
    static void *Hand_task(void *arg)
    {
        ThreadDate *thread = static_cast<ThreadDate *>(arg);
        thread->self->Server(thread->sockfd, thread->addr);
        return nullptr;
    }
    void Loop()
    {
        _isrunning = true;
        while (true)
        {
            struct sockaddr_in peer;
            memset(&peer, 0, sizeof(peer));
            socklen_t len = sizeof(peer);
            int sockfd = ::accept(_listensockfd, (struct sockaddr *)&peer, &len);
            if (sockfd < 0)
            {
                LOG(WARNING, "accept fail")

                //     LOG(INFO, "accept success")
                //     pid_t id = fork();
                //     if (id == 0)
                //     {
                //         ::close(_listensockfd);
                //         pid_t rid = fork();
                //         if (rid == 0)
                //         {
                //             Server(sockfd, peer);
                //         }
                //         exit(0);
                //     }
                //     waitpid(id, nullptr, 0);
                //     ::close(sockfd);
                // }
            }
            else
            {
                pthread_t thread;
                ThreadDate *th = new ThreadDate(sockfd, peer, this);
                pthread_create(&thread, nullptr, Hand_task, th);
            }
        }
        _isrunning = false;
    }
    ~TcpServer()
    {
        ::close(_listensockfd);
    }

private:
    int _listensockfd;
    int _port;
    bool _isrunning;
    fun fun_t;
};