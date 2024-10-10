#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <unistd.h>
#include <stdarg.h>
#include <time.h>
#include <pthread.h>
#include <fstream>
enum Level
{
    INFO = 0,
    DEBUG,
    WARNING,
    ERROR,
    FATAL

};
std::string Level_tostring(int level)
{
    switch (level)
    {
    case INFO:
        return "INFO";
    case DEBUG:
        return "DEBUG";
    case WARNING:
        return "ERROR";
    case ERROR:
        return "ERROR";
    case FATAL:
        return "FATAL";
    default:
        return "Unkown";
    }
}

pthread_mutex_t _glock = PTHREAD_MUTEX_INITIALIZER;
bool _is_save = false;
const std::string filename = "log.txt";

void SaveLog(const std::string context)
{
    std::ofstream infile;
    infile.open(filename,std::ios::app);
    if(!infile.is_open())
    {
        std::cout << "open file failed" << std::endl;
    }
    else
    {
        infile << context;
    }
    infile.close();
}
std::string Gettime()
{
    time_t cur_time = time(NULL);
    struct tm *time_data = localtime(&cur_time);
    if (time_data == nullptr)
    {
        return "None";
    }
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "%d-%d-%d %d:%d:%d",
             time_data->tm_year + 1900,
             time_data->tm_mon + 1,
             time_data->tm_mday,
             time_data->tm_hour,
             time_data->tm_min,
             time_data->tm_sec);
    return buffer;
}
void LogMessage(std::string filename, int line, bool issave, int level, const char *format, ...)
{
    std::string levelstr = Level_tostring(level);
    std::string time = Gettime();
    // 可变参数
    char buffer[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    std::string context = "[" + levelstr + "]" + "[" + time + "]" + "[" + "line : " + std::to_string(line) + "]" + "[" + filename + "]" + ": " + buffer;
    pthread_mutex_lock(&_glock);
    if(!issave)
    {
        std::cout << context << std::endl;
    }
    else{
        SaveLog(context);
    }
    pthread_mutex_unlock(&_glock);
}

#define LOG(level, format, ...)                                          \
    do                                                                   \
    {                                                                    \
        LogMessage(__FILE__, __LINE__, _is_save, level, format, ##__VA_ARGS__); \
    } while (0);
#define EnableFile()    \
    do                  \
    {                   \
        _is_save = true; \
    } while (0);
#define EnableScreen()   \
    do                   \
    {                    \
        _is_save = false;\
    } while (0);