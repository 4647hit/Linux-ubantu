#include <iostream>
#include <set>
#include "Log.hpp"
#include <string>
#include <stdio.h>
class Commad
{
public:
    Commad(std::string path) : _file_path(path)
    {
        Load();
    }
    void Load()
    {
        std::ifstream in(_file_path);
        if (!in.is_open())
        {
            LOG(ERROR, "open %s fail", _file_path.c_str())
            return;
        }
        std::string line;
        while (std::getline(in, line))
        {
            if (line.empty())
            {
                continue;
            }
            // auto it = line.find(sep);
            // if (it == std::string::npos)
            // {
            //     continue;
            // }
            // std::string word = line.substr(0, it);
            // if (word.empty())
            //     continue;
            // std::string hanzi = line.substr(it + sep.size());
            // if (hanzi.empty())
            //     continue;
            _map.insert(line);
            LOG(INFO, "commad load success")
        }
        LOG(INFO, "load success")
        in.close();
    }
    bool CheckCommad(std::string comd)
    {
        auto it = _map.find(comd);
        if (*it == comd)
        {
            LOG(INFO, "can find this commad")
            return false;
        }
        return true;
    }
    std::string Excute(std::string comd)
    {
        if (CheckCommad(comd))
        {
            FILE *result = popen(comd.c_str(), "r");
            if(result == nullptr)
            {
                return "";
            }
            char buffer[1024];
            std::string Result;
            while (fgets(buffer, sizeof(buffer), result) != NULL)
            {
                Result += buffer;
            }
            pclose(result);
            return Result;
        }
        else
        {
            std::cout << "this commad is illegal" << std::endl;
            return "";
        }
    }
    ~Commad()
    {
    }
private:
    std::set<std::string> _map;
    std::string _file_path;
};