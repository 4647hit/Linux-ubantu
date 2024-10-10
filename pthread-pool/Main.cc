#include <iostream>
#include "Threadpool.hpp"
#include "Log.hpp"
#include <memory>
#include <time.h>
#include <stdlib.h>
#include "Task.hpp"
#include <sys/types.h>
#include <unistd.h>
pthread_mutex_t lockA = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t lockB = PTHREAD_MUTEX_INITIALIZER;

void* handA(void* arg)
{
    pthread_mutex_lock(&lockA);
    sleep(300);
    pthread_mutex_lock(&lockB);
    sleep(2);

    pthread_mutex_unlock(&lockB);
    pthread_mutex_unlock(&lockA);
    sleep(12);
    return nullptr;
}
void* handB(void* arg)
{
    pthread_mutex_lock(&lockB);
    sleep(3);
    pthread_mutex_lock(&lockA);
    sleep(2);

    pthread_mutex_unlock(&lockA);
    pthread_mutex_unlock(&lockB);
    sleep(12);
    return nullptr;
}

int main()
{
        std::cout << getpid() << std::endl;
        pthread_t A;
        pthread_t B;
        pthread_create(&A,nullptr,handA,nullptr);
        pthread_create(&B,nullptr,handB,nullptr);
        sleep(100);
        // EnableScreen();
        // std::unique_ptr<Threadpool<task>> pool = std::make_unique<Threadpool<task>>(5);
        // pool->Init_Threadpool();
        // pool->Start();
        // srand(time(NULL) ^ getpid() ^ pthread_self());
        // int tasknum = 10;
        // while (tasknum--)
        // {

        //     int a = rand() % 4 + 2;
        //     int b = rand() % 3 + 5;
        //     usleep(1200);
        //     pool->Enqueue(task(a, b));
        //     LOG(INFO, "task has pushed into queue,a is %d, b is %d", a,b)
        // }

        // pool->Stop();
        // pool->Join();

        return 0;
}