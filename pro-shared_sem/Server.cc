#include"Comm.hpp"

int main()
{
    //获取key值
    key_t k = Get_key();
    int shmid = Creat_sem(k, 4096);
    //挂接
    char* ptr = (char*)Attachshm(shmid);
    sleep(3);

    //通信
    while(1)
    {
        sleep(1);
        printf("Client send: %s\n",ptr);
    }
    //去关联
    Dis_attachshm((void*)ptr);
    Deleteshm(shmid);
    cout << shmid << endl;
    return 0;
}