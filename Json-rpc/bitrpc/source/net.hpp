#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpClient.h>
#include <iostream>
#include <muduo/net/Buffer.h>
#include <muduo/base/CountDownLatch.h>
#include <muduo/net/EventLoopThread.h>
#include "abstract.hpp"
#include "Log.hpp"
#include "Message-type.hpp"
#include "message.hpp"
#include <unordered_map>
#include <mutex>

namespace RPC
{
    class MudouBuffer : public BaseBuffer
    {
    public:
        MudouBuffer(muduo::net::Buffer *buffer) : _buf(buffer)
        {
        }
        using ptr = std::shared_ptr<MudouBuffer>;
        virtual size_t readablesize()
        {
            return _buf->readableBytes();
        }
        virtual int32_t peekInt32()
        {
            // muduo库是网络库，从缓冲区取出4字节整型会进行网络字节序的转换
            return _buf->peekInt32();
        }
        virtual void retrieveInt32() // 删除32
        {
            return _buf->retrieveInt32();
        }
        virtual int32_t readInt32()
        {
            return _buf->readInt32();
        }
        virtual std::string retrieveAsString(size_t len)
        {
            return _buf->retrieveAsString(len);
        }

    private:
        muduo::net::Buffer *_buf;
    };

    class MudouBufferFactory
    {
        template <typename... Args>
        static RPC::BaseBuffer::ptr create(Args &&...args)
        {
            return std::make_shared<MudouBuffer>(std::forward(args)...);
        }
    };
    class LVProtocol : public BaseProtocol
    {
    public:
        //|--len--|--mtype--|--idlen--|--id--|--body--|
        using ptr = std::shared_ptr<LVProtocol>;

    public:
        virtual bool canProcessed(const BaseBuffer::ptr &val)
        {
            int32_t total_len = val->peekInt32();
            if (val->readablesize() < total_len + lenFieldslength)
            {
                return false;
            }
            return true;
        }
        virtual bool OnMessage(const BaseBuffer::ptr &buf, BaseMessage::ptr &msg) override
        {
            // 解析消息
            //|--len--|--mtype--|--idlen--|--id--|--body--|
            int32_t len = buf->readInt32();
            int32_t mtype = buf->readInt32();
            int32_t idlen = buf->readInt32();

            int32_t body_len = len - mTypeFieldslength - IdFieldslength;
            std::string id = buf->retrieveAsString(idlen);
            std::string body = buf->retrieveAsString(body_len);

            msg = MessageFactory::create((Mtype)mtype);
            if (msg.get() == nullptr)
            {
                ELOG("消息解析失败")
                return false;
            }
            bool ret = msg->unserialize(body);
            if (ret == false)
            {
                ELOG("反序列化失败")
                return false;
            }
            msg->setId(id);
            msg->setMtype((Mtype)mtype);
        }
        virtual std::string serialize(const BaseMessage::ptr &ptr) override
        {
            //|--len--|--mtype--|--idlen--|--id--|--body--|
            std::string body = ptr->serialize();
            std::string id = ptr->id();

            auto mtype = htonl((int32_t)ptr->mtype());
            int32_t mtypelen = htonl(mTypeFieldslength);
            int32_t Idlen = htonl(IdFieldslength);

            std::string result;
            int32_t total_len = mTypeFieldslength + IdFieldslength + body.size() + id.size();
            result.reserve(total_len + lenFieldslength);

            result.append((char *)&total_len, lenFieldslength);
            result.append((char *)&mtype, mTypeFieldslength);
            result.append((char *)&id, IdFieldslength);
            result.append(id);
            result.append(body);

            return result;
        }

    private:
        const size_t lenFieldslength = 4;
        const size_t mTypeFieldslength = 4;
        const size_t IdFieldslength = 4;
    };
    class LVProtovolFactory
    {
        public:
        template <typename... Args>
        static RPC::BaseProtocol::ptr create(Args &&...args)
        {
            return std::make_shared<LVProtocol>(std::forward(args)...);
        }
    };
    class MuduoConnection : public BaseConnection
    {
    public:
        using ptr = std::shared_ptr<MuduoConnection>;
        MuduoConnection(const BaseProtocol::ptr &protocol, const muduo::net::TcpConnectionPtr &conn) : _protocol(protocol), _conn(conn)
        {
        }
        virtual void send(const BaseMessage::ptr &msg) override
        {
            std::string message = _protocol->serialize(msg);
            if (message.size())
            {
                _conn->send(message);
            }
        }
        virtual void shutdown() override
        {
            _conn->shutdown();
        }
        virtual bool connected() override
        {
            return _conn->connected();
        }

    private:
        BaseProtocol::ptr _protocol;
        muduo::net::TcpConnectionPtr _conn;
    };
    class MuduoConnectionFactory
    {
        public:
        template <typename... Args>
        static RPC::BaseConnection::ptr create(Args &&...args)
        {
            return std::make_shared<MuduoConnection>(std::forward(args)...);
        }
    };

    class MuduoServer : public BaseServer
    {
    public:
        MuduoServer(int port = 9090) : _server(&_baseloop, muduo::net::InetAddress("127.0.0.1", port), "MuduoServer", muduo::net::TcpServer::kReusePort), _protocol(LVProtovolFactory::create())
        {
        }
        void start() override
        {
            _server.setConnectionCallback(std::bind(&MuduoServer::onConnection, this, std::placeholders::_1));
            _server.setMessageCallback(std::bind(&MuduoServer::onMessage, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));

            _server.start();
            _baseloop.loop();
        }

    public:
        void onConnection(const muduo::net::TcpConnectionPtr &conn)
        {
            if (conn->connected())
            {
                std::cout << "连接建立成功"  << std::endl;
                auto bcon = MuduoConnectionFactory::create(conn, _protocol);
                {
                    std::unique_lock<std::mutex>(_mutex);
                    _conn.insert(std::make_pair(conn, bcon));
                }
                if(_cb_connection) {_cb_connection(bcon);}
            }
            else
            {
                std::cout << "连接断开" << std::endl;
                BaseConnection::ptr moduo_it = MuduoConnectionFactory::create();
                {
                    auto it = _conn.find(conn);
                    if(it == _conn.end())
                    {
                        return false;
                    }
                    muduo_it = it.second;
                    _conn.erase(conn);
                    if(_cb_close){_cb_close(muduo_it)}
                }
            }
        }
        void onMessage(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buf, muduo::Timestamp)
        {
        }

    private:
        BaseProtocol::ptr _protocol;
        muduo::net::EventLoop _baseloop;
        muduo::net::TcpServer _server;
        std::mutex _mutex;
        std::unordered_map<muduo::net::TcpConnectionPtr, BaseConnection::ptr> _conn;
    };
}
