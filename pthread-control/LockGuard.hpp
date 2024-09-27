#include<pthread.h>
#include<iostream>

class Lock
{
    Lock(pthread_mutex_t mutex):_mutex(mutex)
    {
        pthread_mutex_init(&_mutex,nullptr);
        pthread_mutex_lock(&_mutex);
    }
    ~Lock()
    {
        pthread_mutex_destroy(&_mutex);
    }
    pthread_mutex_t& _mutex;
};