#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

const int num = 5;
void Work()
{
    int x = 5;
    while(x--)
    {
        printf("hello world\n");
    }
}
int main()
{
    for(int i = 0; i < num; i++)
    {
        pid_t id = fork();
        if(id < 0)
        {
            break;
        }
        if (id == 0)
        {
            //子进程的运行
            printf("I am child，pid:%d,ppid:%d\n",getpid(),getppid());
            sleep(1);
            Worker();
            exit(0);
        }
        sleep(1);
        
        printf("I am father, pid:%d\n",getpid());
    }
    // pid_t id = fork();
    // if(id < 0)
    // {
    //     return 2;
    // }
    // printf("--------------------------------------------------------\n");
    // sleep(1);
    // if(id == 0)
    // {
    //     //子进程
    //     while(1)
    //     {
    //         printf("I am child, pid:%d, ppid:%d\n", getpid(),getppid());
    //         sleep(1);
    //     }
    // }
    // else
    // {
    //     //父进程
    //     while(1)
    //     {
    //         printf("I am father, pid:%d, ppid:%d\n", getpid(),getppid());
    //         sleep(1);
    //     }
    // }
    return 0;
}
