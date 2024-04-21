#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc, char* argv[],char* env[])
{
    extern char** environ;
    for(int i = 0; environ[i]; i++)
    {
        printf("environ[%d] -> %s\n",i,environ[i]);
    }
    // printf("I am a process , pid: %d, ppid：%d\n",getpid(),getppid());
    // for(int i = 0; env[i]; i++)
    // {
    //     printf("---------------env[%d] : %s\n",i,env[i]);
    // }
    // pid_t id = fork();
    // if(id == 0)
    // {
    //     printf("——-------------------------\n");
    //     printf("I am a child , pid: %d, ppid：%d\n",getpid(),getppid());
    //     for(int i = 0; env[i]; i++)
    //     {
    //         printf("---------------env[%d] : %s\n",i,env[i]);
    //     }
    // }
    // sleep(1);
    //   for(int i = 0; env[i]; i++)
    //   {
    //     printf(" env[%d] ---> %s\n",i,env[i]);
    //   }
    //   return 0;
//    if(argc != 4)
//    {
//         printf("操作错误，请输入标准命令：./Main.c -[add|mul|sub|div] int int \n");
//    }
//    else
//    {
//         int x = atoi(argv[2]);
//         int y = atoi(argv[3]);
//         if(strcmp(argv[1],"-add") == 0)
//         {
//             printf("%d + %d = %d\n",x,y,x+y);
//         }
//         else if(strcmp(argv[1],"-sub") == 0)
//         {
//             printf("%d - %d = %d\n",x,y,x-y);
//         }
//         else if(strcmp(argv[1],"-mul") == 0)
//         {
//             printf("%d * %d = %d\n",x,y,x*y);
//         }
//         else if(strcmp(argv[1],"-div") == 0)
//         {
//             printf("%d / %d = %d\n",x,y,x/y);
//         }
//         else 
//         {
//             printf("unkown\n");
//         }
//    }
//    return 0;

    // for(int i = 0; i < argc; i++)
    // {
    //     printf("argv[%d]:%s\n",i,argv[i]);
    // }
    // return 0;
    // for(int i = 0; argv[i]; i++)
    // {
    //     printf("argv[%d]:%s\n",i,argv[i]);
    // }
    // return 0;
}