#include <iostream>
#include <memory>
#include "Udpserver.hpp"
#include "Dict.hpp"
#include <functional>
using namespace dict_trans;
void Usage()
{
    std::cout << "./Main.cc  server_port\n"<< std::endl;
}
int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        Usage();
        return 0;
    } 
    EnableScreen();
    //std::string server_ip = argv[1];
    int server_port = std::stoi(argv[1]);
    dict tr;
    std::unique_ptr<Udpserver> ptr = std::make_unique<Udpserver>(server_port,std::bind(&dict::Translation, &tr, std::placeholders::_1));
    ptr->InitServer();
    ptr->Start();
    return 0;
}