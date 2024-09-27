#include <iostream>
#include <vector>
#include <queue>

template <typename T>
class blockqueue
{
    typedef int data;
private:
    bool isfull()
    {
        return self.size() == capacity;
    }

public:
    blockqueue(int cap = 20) : capacity(cap)
    {
        pthread_mutex_init(&_glock, nullptr);
        pthread_cond_init(&_product_cond, nullptr);
        pthread_cond_init(&_consume_cond, nullptr);
    }
    void Enqueue(const T& in)
    {
        // 1.加锁
        pthread_mutex_lock(&_glock);
        while(isfull())
        {
            _product_wait_num++;
            pthread_cond_wait(&_product_cond, &_glock);//存在伪唤醒情况(消费一个数据，却唤醒了多个生产线程)，可以将外部判断语句变为while
            _product_wait_num--;
        }
        self.push(std::move(in));

        //1.1唤醒消费线程
        if(_consume_wait_num > 0)//有消费者在等，才需要唤醒
            pthread_cond_signal(&_consume_cond);
        // 2.解锁
        pthread_mutex_unlock(&_glock);
    }
    void Popqueue(T* out)
    {
        // 1.加锁
        pthread_mutex_lock(&_glock);
        while(self.empty())//避免多个线程在被唤醒时，只有一个线程持有锁，其他线程在锁下等待失败，继续向下执行时，出现问题。
        {
            _consume_wait_num++;
            pthread_cond_wait(&_consume_cond, &_glock);//1.让线程进入休眠，当被唤醒后，需要重新持有锁后方能从该位置继续执行。
            _consume_wait_num--;
        }
        *out =  self.front();
        self.pop();
        //1.1唤醒生产的线程
        if(_product_wait_num > 0)//有生产者在等，才需要唤醒
            pthread_cond_signal(&_product_cond);
        // 2.解锁
        pthread_mutex_unlock(&_glock);
    }
    ~blockqueue()
    {
        pthread_mutex_destroy(&_glock);
        pthread_cond_destroy(&_product_cond);
        pthread_cond_destroy(&_consume_cond);
    }

private:
    int capacity; // 容量
    std::queue<T> self;

    pthread_mutex_t _glock; // 互斥锁

    pthread_cond_t _product_cond; // 生产者条件变量
    pthread_cond_t _consume_cond; // 消费者条件变量

    int _product_wait_num;//等待线程数
    int _consume_wait_num;

};
