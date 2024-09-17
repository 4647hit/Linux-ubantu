#include <iostream>
#include "ThreadMode.hpp"
#include <vector>

int g_ticket = 1000;
using namespace ThreadModule;
template <class T>
class ThreadData
{
public:
    ThreadData(int& data,const std::string str):_data(data),name(str)
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
private:
    int &_data;
    std::string name;
};
void funtion(ThreadData<int>* td)
{
    while (1)
    {
        if (g_ticket > 0)
        {
            std::cout << td->Getname()  << " get ticket, remain ticket number: " << td->Geticket() << std::endl;
            td->buyticket();
        }
        else
        {
            break;
        }
    }
}
const int num = 5;
int main()
{
    std::vector<Thread<ThreadData<int>*>> thread;  
    for(int i = 0; i < num ; i++)
    {
        char threadname[64];
        snprintf(threadname, 64, "Thread-%d", i + 1);
        ThreadData<int> num(g_ticket,threadname);
        Thread<ThreadData<int>*> date(funtion,&num, threadname);

        date.Start();
        thread.emplace_back(date);
    }

    for(auto& e : thread)
    {
        e.Join();
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