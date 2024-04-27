#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

#define SIZE 1024
#define argc 128
#define SYM  " "
char* argv[argc];
char pwd[SIZE];


const char* HostName()
{
    char* hostname = getenv("HOSTNAME");
    if(hostname)
    {
        return hostname;
    }
    else
    {
        return "NONE";
    }
}
const char* UserName()
{
    char* username = getenv("USER");
    if(username)
    {
        return username;
    }
    else
    {
        return "NONE";
    }
}
const char* Currentdir()
{
    char* dirname = getenv("PWD");
    if(dirname)
    {
        return dirname;
    }
    else
    {
        return "NONE";
    }
}
char* Home()
{
    char* home = getenv("HOME");
    if(home)
    {
        return home;
    }
    else
    {
        return NULL;
    }
}
int interactive(char* command)
{
    printf("[%s@%s -- %s]$",UserName(),HostName(),Currentdir());
    fgets(command,SIZE,stdin);
    command[strlen(command) - 1] = 0;
    return strlen(command);
}
void Split(char* command)
{
    int i = 0;
    argv[i++] = strtok(command,SYM);//argv为全局变量，用于存放字符变量
    while(argv[i++] = strtok(NULL, SYM));//SYM为空格，这里是个宏
}

void Execute()
{
    pid_t id = fork();
    if(id == 0)
    {
        execvp(argv[0],argv);
    }
    pid_t rid = waitpid(id,NULL,0);
    // if(rid > 0)
    // {
    //     printf("wait success, pid: %d\n",rid);
    // }
}
int Built_in_com()//用返回值判断是否为内建命令，如果是返回 1， 不是返回 0.
{
    int ret = 0;
    if(strcmp(argv[0],"cd") == 0)
    {
       ret = 1;
       char* home = argv[1];
       if(!home) home = Home(); 
       chdir(home);
       snprintf(pwd,SIZE,"PWD=%s",home);
       putenv(pwd);
    }
    return ret;
}
int main()
{
    while(1)//让shell持续运行
    {
        char command[SIZE];
        //1.获取用户指令并打出命令行提示符
        int ret = interactive(command);
        if(!ret)
        {
            continue;
        }
        //2.切割命令行
        Split(command);
        //3.处理内建命令
        ret = Built_in_com();
        if(ret)
        {
            continue;
        }
        //4.执行命令
        Execute();
    }
    // for(int i = 0; argv[i];i++)
    // {
    //     printf("argv[%d]:%s\n",i,argv[i]);
    // }
    return 0;
}