#include <iostream>
#include "TcpServer.hpp"
#include <memory>
#include "Log.hpp"
#include "Command.hpp"
void Usage()
{
    std::cout << "correct use: ./server Port" << std::endl;
}
int main(int argc, char* argv[])
{
    if(argc != 2) 
    {
        Usage();
        exit(-1);
    }
    int port = std::stoi(argv[1]);
    Commad com("./safe.txt");
    fun comExcute = std::bind(&Commad::Excute,&com, std::placeholders::_1);
    std::unique_ptr<TcpServer> ptr = std::make_unique<TcpServer>(port,comExcute);
    ptr->Init_Server();
    ptr->Loop();
    
    return 0;
}