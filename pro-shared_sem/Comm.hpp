#include<iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <cerrno>
#include <cstring>
using namespace std;

const char* pathname = "./Shm_sem";
const int proj_id = 1024;

key_t Get_shm_key()
{
    key_t key = ftok(pathname,proj_id);
    if(key < 0)
    {
        cout << "Creat fail errno_num is " << errno <<  strerror(errno) << endl;
    }
    return key;
}
int Creat_shm_sem(key_t key, size_t size, int shmflg)
{
    
    int shmid = shmget(key,size,shmflg);
    if(shmid < 0)
    {
        cout << "Creat fail errno_num is " << errno << " " <<  strerror(errno) << endl;
    }
    return shmid;

}

int Creat_sem(key_t key, size_t size)
{
    return  Creat_shm_sem(key,size,IPC_CREAT | IPC_EXCL);
}
key_t Get_key()
{
    return Get_shm_key();
}
// class shm
// {
// public:
// }