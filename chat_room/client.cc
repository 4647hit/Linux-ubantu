#include <iostream>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include "Log.hpp"
#include <strings.h>
#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>
#include "ThreadMode.hpp"
#include "Threadpool.hpp"
using namespace std;
using namespace ThreadModule;
void Usage()
{
    std::cout << "./Main.cc server_ip  server_port\n"
              << std::endl;
}
int InitClient(struct sockaddr_in &client, int argc, char *argv[])
{
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
    {
        LOG(FATAL, "socket fail...")
        exit(-1);
    }

    bzero(&client, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons(stoi(argv[2]));
    client.sin_addr.s_addr = inet_addr(argv[1]);
    return fd;
}
pthread_mutex_t glock = PTHREAD_MUTEX_INITIALIZER;
void se(int fd, struct sockaddr_in *client, std::string name)
{
    while (true)
    {
        //pthread_mutex_lock(&glock);
        std::string message;
        std::cout << "[" << name << "]" << " | Please Enter: ";
        std::getline(std::cin, message);
        sendto(fd, message.c_str(), message.size(), 0, (struct sockaddr *)client, sizeof(*client));
        //pthread_mutex_unlock(&glock);
    }
}
void re(int fd, std::string name)
{
    while (true)
    {
        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        //pthread_mutex_lock(&glock);
        ssize_t n = recvfrom(fd, buffer, sizeof(buffer) - 1,0,(struct sockaddr *)&peer, &len);
        //LOG(INFO, "recv message success")
        if (n > 0)
        {
            //std::cout << std::endl << "[" << name << "] | :" << buffer << std::endl;
            fprintf(stderr,"[%s] |: %s\n", name.c_str(),buffer);
	   fflush(stderr);
        }
        //pthread_mutex_unlock(&glock);
    }
}
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage();
        return 0;
    }
    struct sockaddr_in client;
    int fd = InitClient(client, argc, argv);
    // // 创建套接字
    // int fd = socket(AF_INET, SOCK_DGRAM, 0);
    // if (fd < 0)
    // {
    //     LOG(FATAL, "socket fail...")
    //     exit(-1);
    // }
    // struct sockaddr_in client;
    // bzero(&client, sizeof(client));
    // client.sin_family = AF_INET;
    // client.sin_port = htons(stoi(argv[2]));
    // client.sin_addr.s_addr = inet_addr(argv[1]);
    // client 不需要显示地绑定服务端。OS会在client发送数据时，随机绑定一个端口号
    // 通信
    func_t r = std::bind(&re, fd, std::placeholders::_1);
    func_t s = std::bind(&se, fd, &client, std::placeholders::_1);
    Thread send(s, "sender");
    Thread revc(r, "recver");
    

    send.Start();
    revc.Start();

    send.Join();
    revc.Join();

    // std::string message;
    // while (1)
    // {
    //     struct sockaddr_in peer;
    //     socklen_t len = sizeof(peer);
    //     char buffer[1024];
    //     memset(buffer, 0, sizeof(buffer));
    //     ssize_t n = recvfrom(fd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&peer, &len);
    //     if (n > 0)
    //     {
    //         std::cout << buffer << std::endl;
    //     }
    // }
    return 0;
}
