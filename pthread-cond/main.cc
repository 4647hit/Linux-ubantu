// #include <iostream>
// #include <vector>
// #include <pthread.h>
// #include <unistd.h>
// #include <string>

// #define Num 4

// pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
// pthread_cond_t g_cond = PTHREAD_COND_INITIALIZER;
// void *Slaverwork(void *arg)
// {
//     while (1)
//     {
//         std::string threadname = static_cast<const char *>(arg);
//         // 1、加锁
//         pthread_mutex_lock(&g_mutex);
//         // 1.1条件变量一般在加锁和解锁区域使用
//         pthread_cond_wait(&g_cond, &g_mutex);
//         std::cout << "线程被唤醒, 唤醒名称为： " << threadname << std::endl;
//         // 2、解锁
//         pthread_mutex_unlock(&g_mutex);
//     }
//     delete[] (char *)arg;
//     return nullptr;
// }

// void *Create_Slaver(void *arg)
// {
//     std::vector<pthread_t> *tids = static_cast<std::vector<pthread_t> *>(arg);
//     for (int i = 0; i < 4; i++)
//     {
//         pthread_t tid;
//         char *ptr = new char[64];
//         snprintf(ptr, 64, "pthread - %d", i + 1);
//         pthread_create(&tid, nullptr, Slaverwork, ptr);
//         tids->push_back(tid);
//     }
//     return nullptr;
// }
// void MasterStart(std::vector<pthread_t> &tids)
// {
//     pthread_t tid;
//     int n = pthread_create(&tid, nullptr, Create_Slaver, &tids);
//     if (n == 0)
//     {
//         std::cout << "Master create success" << std::endl;
//     }
//     tids.push_back(tid);
// }
// void Master_awake(std::vector<pthread_t> &tids)
// {
//     int count = 6;
//     std::cout << "Master begin work" << std::endl;
//     while (count--)
//     {
//         sleep(1);
//         pthread_cond_signal(&g_cond);
//     }
//     std::cout << "Master work done " << std::endl;
// }
// void MasterJoin(std::vector<pthread_t> &tids)
// {
//     for (auto &tid : tids)
//     {
//         std::cout << "join success" << std::endl;
//         pthread_join(tid, nullptr);
//     }
// }
// int main()
// {
//     std::vector<pthread_t> tid;
//     MasterStart(tid);
//     Master_awake(tid);
//     MasterJoin(tid);
//     return 0;
// }


#include <iostream>
#include <vector>
#include <pthread.h>
#include <unistd.h>
#include <string>

#define Num 4

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t g_cond = PTHREAD_COND_INITIALIZER;
bool stop_threads = false;

void *Slaverwork(void *arg)
{
    while (true)
    {
        pthread_mutex_lock(&g_mutex);
        while (!stop_threads)
        {
            pthread_cond_wait(&g_cond, &g_mutex);
        }
        pthread_mutex_unlock(&g_mutex);
        break; // Exit the thread
    }
    
    std::string threadname = static_cast<const char *>(arg);
    std::cout << "线程被唤醒, 唤醒名称为： " << threadname << std::endl;
    delete[] (char *)arg;
    return nullptr;
}

void *Create_Slaver(void *arg)
{
    std::vector<pthread_t> *tids = static_cast<std::vector<pthread_t> *>(arg);
    for (int i = 0; i < Num; i++)
    {
        pthread_t tid;
        char *ptr = new char[64];
        snprintf(ptr, 64, "pthread - %d", i + 1);
        pthread_create(&tid, nullptr, Slaverwork, ptr);
        tids->push_back(tid);
    }
    return nullptr;
}

void MasterStart(std::vector<pthread_t> &tids)
{
    pthread_t tid;
    int n = pthread_create(&tid, nullptr, Create_Slaver, &tids);
    if (n == 0)
    {
        std::cout << "Master create success" << std::endl;
    }
    tids.push_back(tid);
}

void Master_awake(std::vector<pthread_t> &tids)
{
    int count = 6;
    std::cout << "Master begin work" << std::endl;
    while (count--)
    {
        sleep(1);
        pthread_mutex_lock(&g_mutex);
        pthread_cond_signal(&g_cond);
        pthread_mutex_unlock(&g_mutex);
    }
    pthread_mutex_lock(&g_mutex);
    stop_threads = true;
    pthread_cond_broadcast(&g_cond); 
    pthread_mutex_unlock(&g_mutex);
    std::cout << "Master work done " << std::endl;
}

void MasterJoin(std::vector<pthread_t> &tids)
{
    for (auto &tid : tids)
    {
        pthread_join(tid, nullptr);
        std::cout << "join success" << std::endl;
    }
}

int main()
{
    std::vector<pthread_t> tid;
    MasterStart(tid);
    Master_awake(tid);
    MasterJoin(tid);
    return 0;
}
