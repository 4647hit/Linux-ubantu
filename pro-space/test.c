// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<sys/types.h>
// int num;
// int nums = 100;

// int main(int argc, char* argv[],char* env[])
// {
//     int ret = 0;
//     pid_t id = fork();
//     if(id == 0)
//     {
//         while(1)
//         {
//             printf("child, pid:%d, ppid: %d,num: %d,&num: %p\n",getpid(),getppid(),num,&num);
//             ret++;
//             if(ret == 7)
//             {
//                 num = 100;
//                 printf("child change nums\n");
//             }
//             sleep(2);
//         }
//     }
//     else
//     {

//         while(1)
//         {
//             printf("father, pid:%d, ppid: %d,num: %d,&num: %p\n",getpid(),getppid(),num,&num);
//             sleep(2);
//         }
//     }


//    for(int i = 0; argv[i]; i++)
//    {
//         printf("&argv[%d] = %p\n",i,argv + i);
//    }
//       for(int i = 0; env[i]; i++)
//    {
//         printf("&env[%d] = %p\n",i,env+i);
//    }
    // char* heap1 = (char*)malloc(10);
    // char* heap2 = (char*)malloc(10);
    // char* heap3 = (char*)malloc(10);
    // printf("heap1 addr:%p\n",heap1);
    // printf("heap2 addr:%p\n",heap2);
    // printf("heap3 addr:%p\n",heap3);
    
    // printf("stack head1 addr: %p\n",&heap1);
    // printf("stack head2 addr: %p\n",&heap2);
    // printf("stack head3 addr: %p\n",&heap3);
    // const char* str = "hello";
    // printf("代码区：%p\n",main);
    // printf("常量区：%p\n",str);
    // printf("初始化区域：%p\n",&nums);
    // printf("未初始化区域：%p\n",&num);
    // char* heap = (char*)malloc(10);
    // printf("堆区区域：%p\n",heap);
    // printf("栈区区域：%p\n",&heap);
    // return 0;
}