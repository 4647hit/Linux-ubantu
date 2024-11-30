
#include "Log.hpp"
#include "abstract.hpp"
#include "message.hpp"
#include <iostream>
int main()
{
    // RPC::RpcRequest::ptr rpt = RPC::MessageFactory::create<RPC::RpcRequest>();
    // rpt->setMethod("add");
    // Json::Value param;
    // param["num1"] = 11;
    // param["num2"] = 22;
    // rpt->setParams(param);
    // std::string str = rpt->serialize();
    // std::cout << str << std::endl;

    // RPC::BaseMessage::ptr bmp = RPC::MessageFactory::create(RPC::Mtype::REQ_RPC);
    // bool ret = bmp->unserialize(str);
    // if(ret == false)
    // {
    //     return -1;
    // }
    // ret = bmp->check();
    // if(ret == false)
    // {
    //     return -1;
    // }
    // RPC::RpcRequest::ptr rpt2 = std::dynamic_pointer_cast<RPC::RpcRequest>(bmp);
    // std::cout << rpt2->method() <<std::endl;
    // std::cout << rpt2->params()["num1"] << std::endl;
    //  return 0;

    // RPC::TopicRequest::ptr rpt = RPC::MessageFactory::create<RPC::TopicRequest>();
    // rpt->setTopicKey("add");
    // rpt->setTopictype(TopicOptype::TOPIC_PUBLISH);
    // rpt->setTopicMsg("hello world");
    // std::string str = rpt->serialize();
    // std::cout << str << std::endl;

    // RPC::BaseMessage::ptr bmp = RPC::MessageFactory::create(RPC::Mtype::REQ_TOPIC);
    // bool ret = bmp->unserialize(str);
    // if (ret == false)
    // {
    //     return -1;
    // }
    // ret = bmp->check();
    // if (ret == false)
    // {
    //     return -1;
    // }
    // RPC::TopicRequest::ptr rpt2 = std::dynamic_pointer_cast<RPC::TopicRequest>(bmp);
    // std::cout << rpt2->TopicKey() << std::endl;
    // std::cout << (int)rpt2->Topictype() << std::endl;
    // std::cout << rpt2->TopicMsg() << std::endl;
    // return 0;

    //     RPC::ServiceRequest::ptr rpt = RPC::MessageFactory::create<RPC::ServiceRequest>();
    //     rpt->setServiceMethod("add");
    //     rpt->setServicetype(ServiceOptype::SERVICE_DISCOVERY);
    //     Address host("127.0.0.1", 8888);
    //     rpt->setHost(host);
    //    std::string str = rpt->serialize();
    //     std::cout << str << std::endl;

    //     RPC::BaseMessage::ptr bmp = RPC::MessageFactory::create(RPC::Mtype::REQ_SERVICE);
    //     bool ret = bmp->unserialize(str);
    //     if (ret == false)
    //     {
    //         return -1;
    //     }
    //     ret = bmp->check();
    //     if (ret == false)
    //     {
    //         return -1;
    //     }
    //     RPC::ServiceRequest::ptr rpt2 = std::dynamic_pointer_cast<RPC::ServiceRequest>(bmp);
    //     std::cout << rpt2->method() << std::endl;
    //     std::cout << (int)rpt2->optype() << std::endl;
    //     std::cout << rpt2->Host().first << std::endl;
    //     std::cout << rpt2->Host().second << std::endl;
    //     return 0;

    //     RPC::RpcResponse::ptr rpt = RPC::MessageFactory::create<RPC::RpcResponse>();
    //     rpt->setResult(33);
    //     rpt->setRCode(RPC::RCode::RCODE_OK);

    //    std::string str = rpt->serialize();
    //     std::cout << str << std::endl;

    //     RPC::BaseMessage::ptr bmp = RPC::MessageFactory::create(RPC::Mtype::RSP_RPC);
    //     bool ret = bmp->unserialize(str);
    //     if (ret == false)
    //     {
    //         return -1;
    //     }
    //     ret = bmp->check();
    //     if (ret == false)
    //     {
    //         return -1;
    //     }
    //     RPC::RpcResponse::ptr rpt2 = std::dynamic_pointer_cast<RPC::RpcResponse>(bmp);
    //     std::cout << (int)rpt2->rcode() << std::endl;
    //     std::cout << rpt2->result().asString() << std::endl;

    //     return 0;

    //     RPC::ServiceRequest::ptr rpt2 = std::dynamic_pointer_cast<RPC::ServiceRequest>(bmp);
    //     std::cout << rpt2->method() << std::endl;
    //     std::cout << (int)rpt2->optype() << std::endl;
    //     std::cout << rpt2->Host().first << std::endl;
    //     std::cout << rpt2->Host().second << std::endl;
    //     return 0;

    //     RPC::TopicResponse::ptr rpt = RPC::MessageFactory::create<RPC::TopicResponse>();

    //     rpt->setRCode(RPC::RCode::RCODE_OK);

    //    std::string str = rpt->serialize();
    //     std::cout << str << std::endl;

    //     RPC::BaseMessage::ptr bmp = RPC::MessageFactory::create(RPC::Mtype::RSP_TOPIC);
    //     bool ret = bmp->unserialize(str);
    //     if (ret == false)
    //     {
    //         return -1;
    //     }
    //     ret = bmp->check();
    //     if (ret == false)
    //     {
    //         return -1;
    //     }
    //     RPC::TopicResponse::ptr rpt2 = std::dynamic_pointer_cast<RPC::TopicResponse>(bmp);
    //     std::cout << (int)rpt2->rcode() << std::endl;
    //     return 0;

    RPC::ServiceResponse::ptr rpt = RPC::MessageFactory::create<RPC::ServiceResponse>();
    rpt->setRCode(RPC::RCode::RCODE_OK);
    rpt->setServiceMethod("add");
    rpt->setServicetype(ServiceOptype::SERVICE_DISCOVERY);
    std::vector<Address> host;
    host.push_back(Address("127.0.0.1",8888));
    host.push_back(Address("127.0.0.2",8880));
    rpt->setHost(host);
    std::string str = rpt->serialize();
    std::cout << str << std::endl;
    RPC::BaseMessage::ptr bmp = RPC::MessageFactory::create(RPC::Mtype::RSP_SERVICE);
    bool ret = bmp->unserialize(str);
    if (ret == false)
    {
        return -1;
    }
    ret = bmp->check();
    if (ret == false)
    {
        return -1;
    }
    RPC::ServiceResponse::ptr rpt2 = std::dynamic_pointer_cast<RPC::ServiceResponse>(bmp);
    std::cout << (int)rpt2->rcode() << std::endl;
    std::cout << (int)rpt2->optype() << std::endl;
    std::cout << rpt2->method() << std::endl;
    std::vector<Address> host1 = rpt2->Host();
    for(int i = 0; i < 2 ; i++)
    {
        std::cout << host1[i].first << std::endl;
        std::cout << host1[i].second << std::endl;
    }
    return 0;
}