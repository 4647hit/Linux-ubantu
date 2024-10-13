#pragma once
#include <iostream>
#include <cstring>
#include <unordered_map>
#include "Log.hpp"
#include <fstream>
#include <string>
namespace dict_trans
{
    const std::string Path = "./Dict.txt";
    const std::string sep = ":";

    class dict
    {
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
                auto it = line.find(sep);
                if (it == std::string::npos)
                {
                    continue;
                }
                std::string word = line.substr(0, it);
                if (word.empty())
                    continue;
                std::string hanzi = line.substr(it + sep.size());
                if (hanzi.empty())
                    continue;
                _map.insert(std::make_pair(word, hanzi));
                LOG(INFO, "load success %s %s %s ", word.c_str(), sep.c_str(), hanzi.c_str());
            }
            LOG(INFO, "load success")
            in.close();
        }

    public:
        dict() : _file_path(Path)
        {
            Load();
        }
        std::string Translation(const std::string &word)
        {
            auto it = _map.find(word);
            if (it == _map.end())
            {
                return "";
            }
            else
            {
                return _map[word];
            }
        }
        ~dict()
        {
        }

    private:
        std::string _file_path;
        std::unordered_map<std::string, std::string> _map;
    };
}
