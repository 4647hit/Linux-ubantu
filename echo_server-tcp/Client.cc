#include <iostream>
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string>
#include <netinet/in.h>
#include <cstring>
#include "Log.hpp"
void Usage()
{
    std::cout << "./client ip port" << std::endl;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        Usage();
        return 1;
    }
    struct sockaddr_in client;
    bzero(&client, sizeof(client));
    client.sin_addr.s_addr = inet_addr(argv[1]);
    client.sin_port = htons(std::stoi(argv[2]));
    client.sin_family = AF_INET;
    socklen_t len = sizeof(client);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        LOG(FATAL, "socket fail")
        return 1;
    }
    int rcount = connect(sockfd, (struct sockaddr *)&client, len);
    if (rcount != 0)
    {
        LOG(FATAL, "connect fail....")
        return 1;
    }
    LOG(INFO, "connect success")
    while (true)
    {
        std::string message;
        printf("please enter: ");
        std::getline(std::cin, message);
        ssize_t n = ::send(sockfd, message.c_str(), message.size(), 0);
        if (n > 0)
        {
            printf("[server] : ");
            char buffer[1024];
            memset(buffer,0, sizeof(buffer));
            ssize_t rnum = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
            if (rnum < 0)
            {
                LOG(ERROR, "recv fail")
                continue;
            }
            if (rnum == 0)
            {
                break;
            }
            std::cout << buffer;
        }
        else
        {
            LOG(ERROR, "send fail")
            break;
        }
        std::cout << std::endl;
    }
    ::close(sockfd);
    return 0;
}