#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define filename "file.txt"
int main()
{
    //使用系统调用
    const char* str = "hello world\n";
    write(1,str,strlen(str));
    //使用C语言的相关接口
    const char* str1 = "hello fwrite\n";
    fwrite(str1,strlen(str1),1,stdout);

    const char* str2 = "hello fprintf\n";
    fprintf(stdout,"%s",str2);
    fork();
    return 0;

    // close(0);
    // int fd = open("long.txtS",O_RDONLY);
    // int a = 0;
    // scanf("%d",&a);
    // printf("%d\n",a);
    // return 0;

    // printf("%d\n",stdin->_fileno); // _fileno是FILE结构体中文件描述符的成员名
    // printf("%d\n",stdout->_fileno);
    // printf("%d\n",stderr->_fileno);
    // int fd1 = open("log1.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
    // int fd2 = open("log2.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
    // int fd3 = open("log3.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
    // int fd4 = open("log4.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
    // int fd5 = open("log5.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
    // printf("fd1:%d\n",fd1);
    // printf("fd2:%d\n",fd2);
    // printf("fd3:%d\n",fd3);
    // printf("fd4:%d\n",fd4);
    // printf("fd5:%d\n",fd5);

    // int fd = open("log.txt",O_WRONLY|O_CREAT|O_TRUNC,0666);
    // if(fd == -1)
    // {
    //     perror("open fail");
    //     return 1;
    // }

    // const char* str = "hello world\n";
    // write(fd,str,strlen(str));
    // close(fd);
    // return 0;
    // printf("hello world\n");
    // fprintf(stdout,"hello world\n");
    // fputs("hello\n",stdout);
    // FILE* p = fopen(filename,"w");
    // if(p == NULL)
    // {
    //     perror("fopen");
    // }
    // const char* str = "hello world\n";
    // printf("pid: %d\n",getpid());
    // while(1)
    // {
    //     fputs(str,p);
    //     sleep(2);
    // }
    // fclose(p);
    // return 0;
}