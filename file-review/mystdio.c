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
    ptr->flush_mode = LINE_FLUSH;
    return ptr;
}

void myclose(myFILE* stream)
{
    my_fflush(stream);
    close(stream->fileno);
    free(stream);
}
void my_fflush(myFILE* fp)
{
    write(fp->fileno, fp->inbuffer,fp->pos);
}
size_t mywrite(myFILE* fp,const char* buf, size_t count)
{
    //1.写入
    memcpy(fp->inbuffer+fp->pos,buf,count);
    fp->pos += count;
    if((fp->flush_mode & LINE_FLUSH) && (fp->inbuffer[fp->pos-1] == '\n'))
    {
        my_fflush(fp);
    }
    //(size_t)write(fp->fileno,buf,count);
    else if((fp->flush_mode & FULL_FLUSH) && fp->pos == fp->cap)
    {
        my_fflush(fp);
    }
    else
    {
        return NULL;
    } 
    return count;  
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