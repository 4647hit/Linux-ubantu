#pragma once
#include<stdio.h>
#define SIZE 1024
#define NONE_FLUSH (1<<1)
#define LINE_FLUSH (1<<2)
#define FULL_FLUSH (1<<3)


typedef struct my_FILE
{
    int fileno;
    char inbuffer[SIZE];//输入缓冲区
    //char outbuffer[SIZE];
    int pos;//位置
    int cap;//容量
    int flush_mode;//刷新模式
}myFILE;


myFILE* myopen(const char* pathname,const char* mode);
void myclose(myFILE* stream);
size_t mywrite(myFILE* fp,const char* buf, size_t count);
//myFILE myread(void* ptr,size_t size,size_t nmeb,FILE* stream);
