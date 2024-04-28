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
char env[SIZE];
int lastcode;

const char* HostName()
{
    putenv("HOSTNAME=iZuf6at4ih6u7gbg2vxumnZ");
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
    if(strcmp(argv[0],"ls") == 0)
    {
        argv[i - 1] = "--color";
        argv[i] = NULL;
    }
}

void Execute()
{
    pid_t id = fork();
    if(id == 0)
    {
        execvp(argv[0],argv);
    }
    int status = 0;
    pid_t rid = waitpid(id,&status,0);
    if(WIFEXITED(status))
    {
        lastcode = WEXITSTATUS(status);
    }
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
       char word[512];
       getcwd(word,512);
       snprintf(pwd,SIZE,"PWD=%s",word);//注意这里数字的大小不能越界
       putenv(pwd);
    }
    else if(strcmp(argv[0],"export") == 0)
    {
        ret = 1;
        if(argv[1]) 
        {
            strcpy(env,argv[1]);
            putenv(env);
        }
    }
    else if(strcmp(argv[0],"echo") == 0)
    {
        ret = 1;  
        if(argv[1] == NULL)
        {
            printf("\n");
        }
        else
        {
            if(argv[1][0] == '$')
            {
                if(argv[1][1] == '?')
                {
                    printf("%d\n",lastcode);
                    lastcode = 0;
                }
                else // echo $环境变量名
                {
                    char* n = getenv(argv[1]+1);
                    if(n)
                    {
                        printf("%s\n",n);
                    }
                    else
                    {
                        printf("The environment variable does not exist\n");
                    }
                }
            }
            else//echo XXXX 这里暂不考虑其他情况，例如echo和重定向符号结合
            {
                printf("%s\n",argv[1]);
            }
        }
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