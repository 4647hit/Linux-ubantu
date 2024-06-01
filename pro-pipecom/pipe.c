#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

void Write(int wfd)
{
    const char* str = "hello linux";
    char buffer[1024];
    int pid = getpid();
    while(1)
    {
        snprintf(buffer,sizeof(buffer),"pid:%d str:%s\n",pid,str);
        write(wfd,buffer,sizeof(buffer));
    }

}
void Read(int rfd)
{
    int cnt = 20;
    char buffer[1024];

    while(cnt--)
    {
        ssize_t n = read(rfd, buffer,sizeof(buffer));
        (void)n;
        printf("%s", buffer);
        sleep(1);
    }
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
    wait(NULL);
}