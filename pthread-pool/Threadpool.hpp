#pragma once
#include <iostream>
#include <queue>
#include <vector>
#include "pthread.h"
#include "Log.hpp"
#include "unistd.h"
#include "ThreadMode.hpp"

using namespace ThreadModule;

static int pthread_num = 4;

template <class T>
class Threadpool
{
private:
    void Lock()
    {
        pthread_mutex_lock(&glock);
    }
    void Unlock()
    {
        pthread_mutex_unlock(&glock);
    }
    void Thread_Sleep()
    {
        pthread_cond_wait(&gcond, &glock);
    }
    void Thread_wakeup()
    {
        pthread_cond_signal(&gcond);
    }
    void Thread_wakeAll()
    {
        pthread_cond_broadcast(&gcond);
    }

public:
    Threadpool(int cap = pthread_num) : _cap(cap), _isrunning(false)
    {
        pthread_mutex_init(&glock, nullptr);
        pthread_cond_init(&gcond, nullptr);
    }
    void Handler_Task(std::string threadname)
    {
        while (true)
        {
            Lock();
            // 任务队列为空，并且在运行
            while (_task_pool.empty() && _isrunning)
            {
                _wait_num++;
                Thread_Sleep();
                LOG(INFO, "%s wake up",threadname.c_str())
                _wait_num--;
            }

            // 任务队列为空，并且不运行了
            if (_task_pool.empty() && !_isrunning)
            {
                Unlock();
                break;
            }
            // 任务队列不为空
            LOG(DEBUG,"%s gain task", threadname.c_str())
            T t = _task_pool.front();
            _task_pool.pop();

            Unlock();
            t();
            LOG(INFO, "task done,result is %s", t.Result().c_str())
            sleep(1);
            // 执行自己的任务
        }
    }
    void Stop()
    {
        Lock();
        _isrunning = false;
        Thread_wakeAll();
        Unlock();
    }
    void Enqueue(const T &task)
    {
        Lock();
        _task_pool.push(task);
        if(_wait_num > 0)
        {
            Thread_wakeup();
        }
        Unlock();
    }
    void Init_Threadpool()
    {
        for (int i = 0; i < _cap; i++)
        {
            std::string name = "thread - " + std::to_string(i + 1);
            _thread_pool.emplace_back(Thread(std::bind(&Threadpool::Handler_Task, this, std::placeholders::_1), name));
            LOG(INFO, "%s init success..." , name.c_str())
        }
        _isrunning = true;
    }
    void Start()
    {
        for (auto &e : _thread_pool)
        {
            LOG(DEBUG,"%s is running..." , e.name().c_str())
            e.Start();
        }
    }
    void Join()
    {
        for (auto &e : _thread_pool)
        {
            usleep(1500);
            LOG(DEBUG, "%s is quiting...", e.name().c_str())
            e.Join();
        }
    }

    ~Threadpool()
    {
        pthread_mutex_destroy(&glock);
        pthread_cond_destroy(&gcond);
    }

private:
    std::vector<Thread> _thread_pool;
    std::queue<T> _task_pool; // 任务队列
    int _cap;                 // 线程数量

    pthread_mutex_t glock;
    pthread_cond_t gcond;
    // 等待线程数
    int _wait_num;

    bool _isrunning; // 线程池是否在跑
};