#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
    extern char** environ;
    char* const arg[] = {"ls","-l","-a",NULL};
    pid_t id = fork();
    if(id == 0)
    {
        //子进程
       printf("execl begin,pid:%d\n",getpid());
       //execl("/usr/bin/ls","ls","-l",NULL);
       //execlp("ls","ls","-l",NULL);
       execve("/usr/bin/ls",arg,environ);
       printf("execl end\n");
       exit(1);
    }
    //父进程
    pid_t rid = waitpid(id,NULL,0);
    if(rid > 0)
    {
        printf("wait success, pid: %d\n",rid);
    }
    // printf("I am process , pid: %d\n",getpid());
    // printf("替换开始\n");
    // execl("/usr/bin/ls","ls","-l",NULL);
    // printf("替换结束\n");
    return 0;
}