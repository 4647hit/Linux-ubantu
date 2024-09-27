#include <iostream>
#include <string>
#include <vector>
#include "ThreadMode.hpp"
#include "unistd.h"
#include "RingQueue.hpp"
using namespace ThreadModule;

typedef int data;
using Ringqueue_t = RingQueue<data>*;
pthread_mutex_t _data_lock = PTHREAD_MUTEX_INITIALIZER;

data cnt = 100;
void Product(Ringqueue_t ptr,std::string name)
{
    
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&_data_lock);
        ptr->Enqueue(cnt);
        std::cout << "product data is :" << cnt << "---[" << name << "]" <<  std::endl;
        cnt--;
        pthread_mutex_unlock(&_data_lock);
    }
}
void Consume(Ringqueue_t ptr,std::string name)
{
    while (1)
    {
        sleep(2);
        data sum;
        ptr->Popqueue(&sum);
        std::cout << "comsume data is : " << sum << "---[" << name << "]" << std::endl;
    }
}
void StartComm(std::vector<Thread<Ringqueue_t>> &thread, int num, Ringqueue_t ptr, func_t<Ringqueue_t> fun,const std::string cname)
{
    for (int i = 0; i < num; i++)
    {
        std::string name = "thread-" + std::to_string(i + 1) + " + " + cname;
        thread.emplace_back(fun, ptr, name);
    }
}
void StartProducter(std::vector<Thread<Ringqueue_t>> &thread, int num, Ringqueue_t ptr)
{
    StartComm(thread, num, ptr, Product, "Productor");
}
void StartConsumer(std::vector<Thread<Ringqueue_t>> &thread, int num, Ringqueue_t ptr)
{
    StartComm(thread, num, ptr, Consume,"Consumer");
}
void Wait(std::vector<Thread<Ringqueue_t>> &threads)
{
    for (auto &e : threads)
    {
        e.Join();
    }
}
void StartAll(std::vector<Thread<Ringqueue_t>>& thread)
{
    for(auto& e : thread)
    {
        e.Start();
    }
}
int main()
{
    RingQueue<data> *ptr = new RingQueue<data>;
    std::vector<Thread<Ringqueue_t>> threads;
    StartProducter(threads, 4, ptr);
    StartConsumer(threads, 5, ptr);
    StartAll(threads);
    Wait(threads);
    return 0;
}