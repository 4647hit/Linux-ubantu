#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
    pid_t id = fork();
    if(id == 0)
    {
        int count = 50;
        while(count--)
        {
            printf("I am child process, pid:%d , ppid:%d\n",getpid(),getppid());
            sleep(1);
        }
        exit(0);
    }
    int ret = 20;
    while(ret--)
    {
        printf("I am father process, pid:%d,ppid:%d\n",getpid(),getppid());
        sleep(1);
    }
    return 0;
}
