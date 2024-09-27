#include <vector>
#include <iostream>
#include <string>
#include <semaphore.h>

template <class T>
class RingQueue
{
private:
    void P(sem_t &sem)
    {
        sem_wait(&sem);
    }
    void V(sem_t &sem)
    {
        sem_post(&sem);
    }
    void Lock(pthread_mutex_t &lock)
    {
        pthread_mutex_lock(&lock);
    }
    void Unlock(pthread_mutex_t &lock)
    {
        pthread_mutex_unlock(&lock);
    }

public:
    RingQueue(int cap = 10) : _cap(cap)
    {
        pthread_mutex_init(&_productor_mutex, nullptr);
        pthread_mutex_init(&_consumer_mutex, nullptr);

        sem_init(&room, 0, 10);
        sem_init(&data, 0, 0);
        _product_index = 0;
        _consume_index = 0;
        queue.resize(cap);
    }
    void Enqueue(const T &date)
    {
        //申请信号量
        P(room);//由于PV操作本身就是原子的，所以这里是不用加锁
        //加锁，保护临界资源
        Lock(_productor_mutex);
        queue[_product_index++] = date;
        _product_index %= _cap;
        Unlock(_productor_mutex);
        V(data);
    }
    void Popqueue(T *date)
    {
        P(data);
        Lock(_consumer_mutex);
        *date = queue[_consume_index];
        queue[_consume_index++] = T();
        (_consume_index) %= _cap;
        Unlock(_consumer_mutex);
        V(room);
    }
    ~RingQueue()
    {
        sem_destroy(&room);
        sem_destroy(&data);

        pthread_mutex_destroy(&_productor_mutex);
        pthread_mutex_destroy(&_consumer_mutex);
    }

private:
    int _cap;
    std::vector<T> queue;
    // 空间信号量
    sem_t room;
    sem_t data;

    // 空间信号量下标
    int _product_index;
    int _consume_index;

    // 多线程需要加锁
    pthread_mutex_t _productor_mutex;
    pthread_mutex_t _consumer_mutex;
};