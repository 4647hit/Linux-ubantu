#include<stdio.h>
#include"mymath1.h"
#include"mymath2.h"

int main()
{
    int a = 10;
    int b = 20;
    int c = Add(a,b);
    int d = Del(a,b);
    printf("%d + %d = %d\n",a,b,c);
    printf("%d - %d = %d\n",a,b,d);
    return 0;
}
