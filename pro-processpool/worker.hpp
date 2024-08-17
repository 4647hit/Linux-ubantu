#pragma once
#include<iostream>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

typedef void(*work_t)(int);

typedef void(*task_t)(int,pid_t);  //函数指针类型

void PrintLog(int fd, pid_t pid)
{
    cout << "sub process: " << pid << ", fd: " << fd<< ", task is : printf log task\n" << endl;
}

void ReloadConf(int fd, pid_t pid)
{
    cout << "sub process: " << pid << ", fd: " << fd<< ", task is : reload conf task\n" << endl;
}

void ConnectMysql(int fd, pid_t pid)
{
    cout << "sub process: " << pid << ", fd: " << fd<< ", task is : connect mysql task\n" << endl;
}
int Task_code()
{
    srand(time(nullptr));
    return rand() % 3; 
}

task_t tasks[3] = {PrintLog, ReloadConf, ConnectMysql};
void worker(int fd)
{
    while(true)
    {
        int new_task_code = 0;
        ssize_t n = read(0,&new_task_code,sizeof(new_task_code));
        if(n == sizeof(new_task_code))
        {
            if(new_task_code >= 3) continue;
            tasks[new_task_code](fd,getpid());
        }
        else
        {
            cout << "task ends" << endl;
            break;
        }
    }
}


