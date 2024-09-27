#include <iostream>
#include <string>
#include <vector>
#include "ThreadMode.hpp"
#include "BlockQueue.hpp"
#include "unistd.h"
using namespace ThreadModule;

typedef int data;
using Blockqueue_t = blockqueue<data>*;
pthread_mutex_t _data_lock = PTHREAD_MUTEX_INITIALIZER;

data cnt = 100;
void Product(Blockqueue_t ptr)
{
    
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&_data_lock);
        ptr->Enqueue(cnt);
        std::cout << "product data is :" << cnt << std::endl;
        cnt--;
        pthread_mutex_unlock(&_data_lock);
    }
}
void Consume(Blockqueue_t ptr)
{
    while (1)
    {
        sleep(2);
        data sum;
        ptr->Popqueue(&sum);
        std::cout << "comsume data is :        " << sum << std::endl;
    }
}
void StartComm(std::vector<Thread<Blockqueue_t>> &thread, int num, Blockqueue_t ptr, func_t<Blockqueue_t> fun)
{
    for (int i = 0; i < num; i++)
    {
        std::string name = "thread - " + std::to_string(i + 1);
        thread.emplace_back(fun, ptr, name);
        thread.back().Start();
    }
}
void StartProducter(std::vector<Thread<Blockqueue_t>> &thread, int num, Blockqueue_t ptr)
{
    StartComm(thread, num, ptr, Product);
}
void StartConsumer(std::vector<Thread<Blockqueue_t>> &thread, int num, Blockqueue_t ptr)
{
    StartComm(thread, num, ptr, Consume);
}
void Wait(std::vector<Thread<Blockqueue_t>> &threads)
{
    for (auto &e : threads)
    {
        e.Join();
    }
}
int main()
{
    blockqueue<data> *ptr = new blockqueue<data>;
    std::vector<Thread<Blockqueue_t>> threads;
    StartProducter(threads, 1, ptr);
    StartConsumer(threads, 1, ptr);
    Wait(threads);
    return 0;
}