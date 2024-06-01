#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
void Write(int wfd)
{
    int cnt = 0;
    const char* str = "hello linux";
    char buffer[1024];
    int pid = getpid();
    while(1)
    {
        sleep(1);
        char c = 'a';
        printf("cnt:%d\n",cnt++);//?为什么刷不出来
        snprintf(buffer,sizeof(buffer),"pid:%d str:%s\n",pid,str);
        write(wfd,&c,1);
    }
}
void Read(int rfd)
{
    char buffer[1024]; 
    int cnt = 10;
    while(cnt--)
    {
        sleep(1);
        ssize_t n = read(rfd, buffer,sizeof(buffer));
        if(n > 0)
            printf("%s", buffer);
        else if(n == 0)
        {
            printf("read pipe done,read file done\n");
            break;
        }
        else{
            break;
        }
    }
    close(rfd);
}
int main()
{
    int pipefd[2];
    int n = pipe(pipefd);
    if(n < 0) return 1;
    printf("%d %d\n",pipefd[0],pipefd[1]);
    pid_t id = fork();
    //写端
    if(id == 0)
    {
        close(pipefd[0]);
        Write(pipefd[1]);
        exit(0);
    }
    //父进程
    close(pipefd[1]);
    Read(pipefd[0]);
    int status = 0;
    int rid = waitpid(id,&status,0);
    if(rid == id)
    {
        printf("exit code:%d , exit signal: %d\n",WEXITSTATUS(status),status&0x7F);
    }
    return 0;
}