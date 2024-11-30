#include <iostream>
#include <jsoncpp/json/json.h>
#include <memory>
#include <sstream>
#include <string>
bool serialize(const Json::Value& val, std::string &body)
{
    // const char* name = "张三";
    // Json::Value stu;
    // stu["na"] = "那人";
    // stu["姓名"] = name;
    // stu["成绩"].append("100");
    // stu["成绩"].append("0分");
    // stu["成绩"].append(3);
    //工厂类
    std::stringstream ss;
    Json::StreamWriterBuilder bui;
    bui["emitUTF8"] = true;
    std::unique_ptr<Json::StreamWriter> bu(bui.newStreamWriter());
    if(bu->write(val, &ss) != 0)
    {
        std::cout << "json serialize failed!\n"<<std::endl;
        return false;
    }
    body = ss.str();
    return true;

}
bool serialize( Json::Value& val, const std::string &body)
{
    Json::CharReaderBuilder crb;
    std::string err;
    std::unique_ptr<Json::CharReader> cr(crb.newCharReader());
    bool ret = cr->parse(body.c_str(),body.c_str() + body.size(),&val,&err);
    if(ret == false)
    {
        std::cout << "unserialize failed\n" << std::endl;
        return false;
    }
    return true;
    
}
bool unserialize(Json::Value& val, const std::string &body)
{
    Json::CharReaderBuilder crb;
    std::unique_ptr<Json::CharReader> cr(crb.newCharReader());
    std::string errs;
    bool ret = cr->parse(body.c_str(),body.c_str()+ body.size(),&val,&errs);
    if(ret = false)
    {
        return false;
    }
    return true;
}
int main()
{
    serialize();
    return 0;
}