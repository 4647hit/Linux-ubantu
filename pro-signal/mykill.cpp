#include<cstdio>
#include<iostream>
#include<stdbool.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
int main(int argc, char* argv[])
{
    int a = 10;
    int b = 0;
    printf("%d",a /b);














    // if(argc != 3)
    // {
    //     sleep(1);
    //     printf("command false : kill + signal + pid\n");
    // }
    // else
    // {
    //     int sig = std::stoi(argv[1] + 1);
    //     pid_t pid = std::stoi(argv[2]);
    //     if(sig > 0 && sig <= 31)
    //     {
    //         if(!kill(pid,sig))
    //         {
    //             printf("killed\n");
    //         }
    //         else
    //         {
    //             printf("killed failed\n");
    //         }
    //     }
    // }
    return 0;
}