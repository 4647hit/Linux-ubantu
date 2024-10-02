#include <iostream>
#include "Threadpool.hpp"
#include "Log.hpp"
#include <memory>
#include <time.h>
#include <stdlib.h>
#include "Task.hpp"

int main()
{
    EnableScreen();
    // LogMessage(__FILE__,__LINE__,DEBUG,"hell0 world");
    std::unique_ptr<Threadpool<task>> pool = std::make_unique<Threadpool<task>>(5);
    // int n = 29;
    pool->Init_Threadpool();
    pool->Start();
    srand(time(NULL) ^ getpid() ^ pthread_self());
    int tasknum = 10;
    while (tasknum--)
    {

        int a = rand() % 4 + 2;
        int b = rand() % 3 + 5;
        usleep(1200);
        pool->Enqueue(task(a, b));
        LOG(INFO, "task has pushed into queue,a is %d, b is %d", a,b)
    }

    pool->Stop();
    pool->Join();

    return 0;
}