#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <vector>
#include <time.h>
#include "ThreadMode.hpp"
// class Task
// {
// public:
//     Task()
//     {
//     }
//     void task_1()
//     {
//         std::cout << "Debug" << std::endl;
//     }
//     void task_2()
//     {
//         std::cout << "Print" << std::endl;
//     }
//     void task_3()
//     {
//         std::cout << "release" << std::endl;
//     }
//     ~Task()
//     {
//     }
// };

// void* task(void* arg)
// {

//     Task _task;
//     int* count = (int*)arg;
//     while(1)
//     {
//         sleep(1);
//         if(*count % 3 == 0)
//         {
//             _task.task_1();
//         }
//         else if(*count % 3 == 1)
//         {
//             _task.task_2();
//         }
//         else
//         {
//             _task.task_3();
//         }
//     }
//     delete count;
//     return nullptr;

// }
// static int threadnum = 5;
// int main()
// {

//     std::vector<pthread_t> s;
//     for(int i = 0; i < threadnum; i ++)
//     {
//         srand(time(nullptr));
//         int* count = new int( rand() ^ i  % threadnum);
//         pthread_t pthread;
//         //char* name = new char[64];
//        // snprintf(name,64,"thread name is pthread - %d\n", )
//         pthread_create(&pthread,nullptr,task,count);
//         s.push_back(pthread);
//     }
//     // for(auto& res : s)
//     // {
//     //     pthread_join(res,nullptr);
//     // }
//     return 0;
// }
// std::string change_to(pthread_t tid)
// {
//     char num[64];
//     snprintf(num, sizeof(num), "0x%lx", tid);
//     return num;
// }
// __thread int cnt = 100;
// void *handler1(void *arg)
// {
//     while (1)
//     {
//         cnt--;
//         std::cout << (char*)arg << " cnt : " <<cnt << " &cnt : " << &cnt << std::endl;
//         sleep(1);
//     }
//     return nullptr;
// }
// void *handler2(void *arg)
// {
//     while (1)
//     {
//         cnt--;
//         std::cout << (char*)arg << " cnt : " <<cnt << " &cnt : " << &cnt << std::endl;
//         sleep(1);
//     }
//     return nullptr;
// }
// int main()
// {
//     pthread_t tid1;
//     pthread_t tid2;
//     pthread_create(&tid1, nullptr, handler1, (void*)"pthread - 1");
//     pthread_create(&tid2, nullptr, handler2, (void*)"pthread - 2");
//     sleep(100);
//     pthread_join(tid1,nullptr);
//     pthread_join(tid2,nullptr);
//     return 0;
// }

// using namespace std;

// static int count = 5;
// void* handler(void *arg)
// {
//     string name = static_cast<char*> (arg);
//     while (1)
//     {
//         sleep(1);
//         std::cout << "I am "<< name << "pid is : " << getpid() << endl;
//     }
//     return nullptr;
// }
// int main()
// {
//     pthread_t thread;
//     pthread_create(&thread, nullptr, handler, nullptr);
//     // while(1)
//     // {
//     //     sleep(1);
//     //     std::cout << "I am pthread -2 " <<  "pid is : " << getpid() << endl;
//     // }
//     pthread_join(thread,nullptr);
//     sleep(2);
//     return 0;
// }
// using namespace ThreadModule;

// void print(int &cnt)
// {
//     while (cnt)
//     {
//         std::cout << "hello I am myself thread, cnt: " << cnt-- << std::endl;
//         sleep(1);
//     }
// }
void print(int& cnt)
{
    while(cnt--)
    {
        sleep(1);
        std::cout << "hello :" << cnt << std::endl;
    }
}
int main()
{
    using namespace ThreadModule;
    Thread<int> tid(print,100);
    tid.Start();
    tid.Join();
    return 0;
}
