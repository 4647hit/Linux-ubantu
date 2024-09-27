// #include <iostream>
// #include <pthread.h>
// #include <unistd.h>
// #include <string>
// #include <functional>

// namespace ThreadModule
// {
//     template <typename T>
//     using fun_t = std::function<void(T)>;

//     template <typename T>
//     class thread
//     {
//     public:
//         void Excute()
//         {
//             _funtion(_data);
//         }

//     public:
//         thread(fun_t<T> func, T&& data, const std::string &name = "none-name")
//             : _funtion(func), _data(data), _name(name)
//         {
//         }
//         static void *pthread_funtion(void *arg)
//         {

//             thread<T> *self = std::static_cast<thread<T> *>(arg);
//             self->Excute();
//             return nullptr;
//         }
//         void Start()
//         {
//             pthread_t tid;
//             pthread_create(&tid, nullptr, pthread_funtion, this);
//             _tid = tid;
//             _status = true;
//         }
//         void Join()
//         {
//             pthread_join(_tid, nullptr);
//             _status = false;
//         }
//         void detach()
//         {
//             pthread_detach(_tid);
//         }
//         ~thread()
//         {
//         }

//     private:
//         std::string _name;
//         pthread_t _tid;
//         fun_t<T> _funtion;
//         T &_data;
//         bool _status;
//     };
// }

#ifndef __THREAD_HPP__
#define __THREAD_HPP__

#include <iostream>
#include <string>
#include <unistd.h>
#include <functional>
#include <pthread.h>

namespace ThreadModule
{
    template<typename T>
    using func_t = std::function<void(T,std::string name)>;
    // typedef std::function<void(const T&)> func_t;

    template<typename T>
    class Thread
    {
    public:
        void Excute()
        {
            _func(_data,_threadname);
        }
    public:
        Thread(func_t<T> func, T data, const std::string name="none-name")//右值
            : _func(func), _data(data), _threadname(name), _stop(true)
        {}
        static void *threadroutine(void *args) // 类成员函数，形参是有this指针的！！
        {
            Thread<T> *self = static_cast<Thread<T> *>(args);
            self->Excute();
            return nullptr;
        }
        bool Start()
        {
            int n = pthread_create(&_tid, nullptr, threadroutine, this);
            if(!n)
            {
                _stop = false;
                return true;
            }
            else
            {
                return false;
            }
        }
        void Detach()
        {
            if(!_stop)
            {
                pthread_detach(_tid);
            }
        }
        void Join()
        {
            if(!_stop)
            {
                pthread_join(_tid, nullptr);
            }
        }
        std::string name()
        {
            return _threadname;
        }
        void Stop()
        {
            _stop = true;
        }
        T& Data()
        {
            return _data;
        }
        ~Thread() {}

    private:
        pthread_t _tid;
        std::string _threadname;
        T _data;  // 为了让所有的线程访问同一个全局变量
        func_t<T> _func;
        bool _stop;
    };
}

#endif