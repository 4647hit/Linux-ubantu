#include"Comm.hpp"
#include"pipe.hpp"
int main()
{

    Fifo fifo(Path);
    int fd = open(Path,O_RDONLY);
    //获取key值re
    key_t k = Get_key();
    int shmid = Creat_sem(k, 4096);
    //挂接
    char* ptr = (char*)Attachshm(shmid);
    sleep(3);

    char buffer[1024];
    int cnt = 27;
    //通信
    while(cnt--)
    {
        //等待写入Client写入
        read(fd,buffer,sizeof(buffer) - 1);
        sleep(1);
        printf("Client send: %s\n",ptr);
    }
    //去关联
    Dis_attachshm((void*)ptr);
    Deleteshm(shmid);
    cout << shmid << endl;
    close(fd);
    return 0;
}