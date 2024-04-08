#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
//	int a = 0;
//	scanf("%d",&a);
//	printf("%d\n",a);
//	return 0;
        while(1)
	{
		printf("I am process, pid:%d\n",getpid());
		sleep(1);
	}
	return 0;
}
