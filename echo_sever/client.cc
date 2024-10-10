#include <iostream>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include "Log.hpp"
#include <strings.h>
#include <arpa/inet.h>
#include <cstring>
#include <netinet/in.h>
using namespace std;
void Usage()
{
    std::cout << "./Main.cc server_ip  server_port\n"
              << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage();
        return 0;
    }
    // 创建套接字
    int fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (fd < 0)
    {
        LOG(FATAL, "socket fail...")
        exit(-1);
    }
    struct sockaddr_in client;
    bzero(&client, sizeof(client));
    client.sin_family = AF_INET;
    client.sin_port = htons(stoi(argv[2]));
    client.sin_addr.s_addr = inet_addr(argv[1]);
    // client 不需要显示地绑定服务端。OS会在client发送数据时，随机绑定一个端口号
    // 通信
    std::string message;
    while (1)
    {
        std::cout << "Please Enter: ";
        std::getline(std::cin, message);
        sendto(fd, message.c_str(), message.size(), 0, (struct sockaddr *)&client, sizeof(client));

        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        char buffer[1024];
        memset(buffer, 0 , sizeof(buffer));
        ssize_t n = recvfrom(fd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr *)&peer, &len);
        if (n > 0)
        {
            std::cout << "server said: "<< buffer << std::endl;
        }
    }
    return 0;
}