#include "Comm.hpp"

int main()
{
    key_t key = Get_key();
    //获取shmid
    int shmid = Get_shm(key,4096);
    //挂接
   char* ptr = (char*)Attachshm(shmid);
    memset(ptr,0, 4096);
    for(char e = 'a'; e <= 'z'; e++)
    {
        sleep(1);
        ptr[e-'a'] = e; 
    }
    sleep(1);
    //去关联
    Dis_attachshm((void*)ptr);
    return 0;
}