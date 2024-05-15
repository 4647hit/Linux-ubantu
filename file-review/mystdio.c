#include"mystdio.h"
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

myFILE* myopen(const char* pathname,const char* mode)
{
    int flag = 0;
    if(strcmp(mode,"r") == 0)
    {
        flag |= O_RDONLY;
    }
    else if(strcmp(mode,"w") == 0)
    {
        flag |= O_TRUNC;
    }
    else if(strcmp(mode,"a") == 0)
    {
        flag |= O_APPEND;
    }
    else
    {
        return NULL;
    }
    int fd = 0;
    if(flag & O_RDONLY == 0)
    {
        fd = open(pathname,flag);
    }
    else if(flag & O_TRUNC == 0)
    {
        flag |= O_CREAT;
        flag |= O_WRONLY;
        fd = open(pathname,flag,0666);
    }
    else if(flag & O_APPEND == 0)
    {
        flag |= O_CREAT;
        flag |= O_WRONLY;
        fd = open(pathname,flag,0666);
    }
    else
    {
        return NULL;
    }
    if(fd < 0)
    {
        return NULL;
    }
    myFILE* ptr = (myFILE*)malloc(sizeof(myFILE));
    if(ptr == NULL)
    {
        return NULL;
    }
    ptr->fileno = fd;
    ptr->cap = SIZE;
    ptr->pos = 0;
    return ptr;
}

void myclose(myFILE* stream)
{
    close(stream->fileno);
    free(stream);
}
size_t mywrite(myFILE* fp,const char* buf, size_t count)
{
    return (size_t)write(fp->fileno,buf,count);   
}
myFILE myread(void* ptr,size_t size,size_t nmeb,FILE* stream);



int main()
{
    const char* filename = "./log.txt";
    myFILE* fp = myopen(filename,"w");
    const char* ptr = "hello world\n";
    mywrite(fp,ptr,strlen(ptr));
    //myclose(fp);
    return 0;
}