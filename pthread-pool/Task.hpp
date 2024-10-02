#pragma once
#include <iostream>

using namespace std;
class task
{
public:
    task(int a, int b) : _a(a), _b(b)
    {
    }
    std::string Result()
    {
        return to_string(_a) + "+" + to_string(_b) + "=" + to_string(_result);
    }
    void Excute()
    {
        _result = _a + _b;
    }
    void operator()()
    {
        Excute();
    }
    ~task()
    {}

private:
    int _a;
    int _b;
    int _result;
};