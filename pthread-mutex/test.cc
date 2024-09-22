#include <iostream>
#include "ThreadMode.hpp"
#include <vector>

int g_ticket = 1000;
using namespace ThreadModule;
template <class T>
class ThreadData
{
public:
    ThreadData(int &data, const std::string str) : _data(data), name(str), total(0)
    {
    }
    ~ThreadData()
    {
    }
    std::string Getname()
    {
        return name;
    }
    void buyticket()
    {
        _data--;
    }
    int Geticket()
    {
        return _data;
    }
    void Plus()
    {
        total++;
    }
    void Total()
    {
        std::cout << name << " : " << total << std::endl;
    }

private:
    int &_data;
    std::string name;
    int total;
};
pthread_mutex_t _lock = PTHREAD_MUTEX_INITIALIZER;
void funtion(ThreadData<int> *td)
{
    while (1)
    {
        //加锁
        pthread_mutex_lock(&_lock);
        if (g_ticket > 0)
        {
            std::cout << td->Getname() << " get ticket, remain ticket number: " << td->Geticket() << std::endl;
            td->buyticket();
            pthread_mutex_unlock(&_lock);
            td->Plus();
        }
        else
        {
            pthread_mutex_unlock(&_lock);
            break;
        }
    }
}
const int num = 5;
int main()
{
    std::vector<Thread<ThreadData<int> *>> thread;
    for (int i = 0; i < num; i++)
    {
        // char* threadname = new char[64];
        // snprintf(threadname, 64, "Thread-%d", i + 1);
        std::string threadname = "thread -" + std::to_string(i + 1);
        ThreadData<int> *ptr = new ThreadData<int>(g_ticket, threadname);
        thread.emplace_back(Thread<ThreadData<int> *>(funtion, ptr, threadname));
    }
    for (auto &e : thread)
    {
        e.Start();
    }
    for (auto &e : thread)
    {
        sleep(1);
        e.Data()->Total();
        e.Join();
        delete e.Data();
    }
    return 0;
    // std::vector<pthread_t> pthread;
    // for (int i = 0; i < num; i++)
    // {
    //     pthread_t id;
    //     pthread_create(&id, nullptr, funtion, nullptr);
    //     pthread.emplace_back(id);
    // }
    // for (auto &e : pthread)
    // {
    //     pthread_join(e, nullptr);
    // }
    // return 0;
}