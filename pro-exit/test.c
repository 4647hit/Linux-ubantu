#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#define num 6
typedef void(*fun)();

fun task[num];
void printA()
{
    printf("hello! I am task A\n");
}
void printB()
{
    printf("hello! I am task B\n");
}
void printC()
{
    printf("hello! I am task C\n");
}
void printD()
{
    printf("hello! I am task D\n");
}

void Inittask()
{
    task[0] = printA;
    task[1] = printB;
    task[2] = printC;
    task[3] = printD;
    task[4] = NULL;
}
void CarryTask()
{
    for(int i = 0; task[i]; i++)
    {
        task[i]();
    }
}
int main()
{
    Inittask();
    pid_t id = fork();
    if(id == 0)
    {
        int ret = 5;
        while(ret--)
        {
            printf("I am child process, pid:%d, ppid:%d\n",getpid(),getppid());
            sleep(1);
        }
        printf("子进程即将终止\n");
        exit(1);//开始变僵尸
    }
    //父进程
    while(1)
    {
        int status = 0;
        pid_t t = waitpid(id, &status,WNOHANG);
        if(t > 0)//系统调用成功，并且子进程已经退出
        {
            printf("wait success, pid : %d\n",t);
            break;
        }
        else if(t == 0)//系统调用成功，但子进程没退
        {
            printf("wait success , but child is still running\n");
            //可以干别的事情
            printf("**************** task begin ***************\n");
            CarryTask();
            printf("****************  task end  ***************\n");
        }
        else//系统调用失败
        {
            perror("waitpid\n");
            break;
        }
        sleep(1);
    }
    return 0;
}
// int main()
// {
//     pid_t id = fork();
//     if(id == 0)
//     {
//         int ret = 10;
//         while(ret--)
//         {
//             printf("I am child process, pid:%d, ppid:%d\n",getpid(),getppid());
//             sleep(1);
//         }
//         printf("子进程即将终止\n");
//         sleep(1);
//         exit(1);//开始变僵尸
//     }
//     sleep(10);
//     int status = 0;
//     pid_t t = waitpid(id, &status,WNOHANG);
//     if(t > 0)
//     {
//         printf("pid: %d status: %d 收到信号：%d 退出码：%d-->回收成功，即将退出\n",t,status,status&0x7f,WEXITSTATUS(status));
//         //0x7f 表示 0000 0000 0000 0000 0000 0000 0111 1111
//         //0xff 表示 0000 0000 0000 0000 0000 0000 1111 1111
//         sleep(3);
//     }
//     return 0;
// }
// int main()
// {
//     pid_t id = fork();
//     if(id == 0)
//     {
//         int ret = 5;
//         while(ret--)
//         {
//             printf("I am child process, pid:%d, ppid:%d\n",getpid(),getppid());
//             sleep(1);
//         }
//         printf("子进程即将终止\n");
//         sleep(1);
//         exit(1);//开始变僵尸
//     }
//     sleep(10);
//     int status = 0;
//     pid_t t = waitpid(id, &status,0);
//     if(t > 0)
//     {
//         printf("pid: %d status: %d  -->回收成功，即将退出\n",t,status);
//         sleep(3);
//     }
//     return 0;
// }





// enum{
//     success = 0,
//     malloc_err,
//     open_err,
//     close_err
// };
// void my_strerror(int code)
// {
//     switch (code)
//     {
//     case success:
//         printf("success\n");
//         break;
//     case malloc_err:
//         printf("malloc fail\n");
//         break;
//     case open_err:
//         printf("open error\n");
//         break;
//     case close_err:
//         printf("close error\n");
//         break;
//     default:
//         printf("unknow\n");
//         break;
//     }

// }
// int main()
// {
//     printf("hello world");
//     sleep(2);
//     _exit(0);
//     // int code = malloc_err;
//     // my_strerror(code);
//     // return code;
//     // for(int i = 1; i < 200; i++)
//     // {
//     //     printf("%d:%s\n",i,strerror(i));
//     // }
//     // printf("hello world\n");
//     // return 10;
// }