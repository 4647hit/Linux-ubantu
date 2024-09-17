#include<iostream>
#include"ThreadMode.hpp"
   
   
using namespace ThreadModule;

void print(int &cnt)
{
    while (cnt)
    {
        std::cout << "hello I am myself thread, cnt: " << cnt-- << std::endl;
        sleep(1);
    }
}   
int main()
{
    int a = 10;
    Thread<int> t1(print, a);
    t1.Start();
    std::cout << "name: " << t1.name() << std::endl;
    t1.Join();
}