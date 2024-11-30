#include <iostream>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/Buffer.h>
#include <string>
#include <unordered_map>

class DictServer
{
public:
    DictServer(int port = 9090) : _server(&_baseloop, muduo::net::InetAddress("127.0.0.1", port), "DictServer", muduo::net::TcpServer::kReusePort)
    {
        _server.setConnectionCallback(std::bind(&DictServer::onConnection, this, std::placeholders::_1));
        _server.setMessageCallback(std::bind(&DictServer::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
    }
    void Start()
    {
        _server.start();
        _baseloop.loop();
    }

public:
private:
    void onConnection(const muduo::net::TcpConnectionPtr &conn)
    {
        if (conn->connected())
        {
            std::cout << "连接建立成功" << std::endl;
        }
        else
        {
            std::cout << "连接断开" << std::endl;
        }
    }
    void onMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buf, muduo::Timestamp)
    {
        static std::unordered_map<std::string, std::string> dict_map = {{"hello", "你好"}, {"world", "世界"}};
        std::string mes = buf->retrieveAllAsString();
        auto it = dict_map.find(mes);
        std::string res;
        if (it != dict_map.end())
        {
            res = it->second;
        }
        else
        {
            std::cout << "词典中找不到该单词" << std::endl;
        }
        conn->send(res);
    }

private:
    muduo::net::EventLoop _baseloop;
    muduo::net::TcpServer _server;
};
int main()
{
    DictServer ser;
    ser.Start();
    return 0;
}