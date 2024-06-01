#include"mystdio.h"
// #include"mystdio.c"
const char* filename = "./log.txt";
#include<string.h>

int main()
{
    myFILE* fp = myopen(filename,"w");
    const char* ptr = "hello world\n";
    mywrite(fp,ptr,strlen(ptr));
    myclose(fp);
    return 0;
}