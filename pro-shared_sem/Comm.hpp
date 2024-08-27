#include<iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <cerrno>
#include <cstring>
#include <unistd.h>
using namespace std;

const char* pathname = "./file.txt";
const int proj_id = 1024;

key_t Get_shm_key()
{
    key_t key = ftok(pathname,proj_id);
    if(key < 0)
    {
        cout << "Creat fail errno_num is " << errno << " " <<  strerror(errno) << endl;
    }
    return key;
}
int Creat_shm_sem(key_t key, size_t size, int shmflg)
{
    
    int shmid = shmget(key,size,shmflg);
    if(shmid < 0)
    {
        cout << "Creat sem errno_num is " << errno << " " <<  strerror(errno) << endl;
    }
    return shmid;

}
int Get_shm(key_t key,int size)
{
    return Creat_shm_sem(key,size,IPC_CREAT);
}

int Creat_sem(key_t key, int size)
{
    return Creat_shm_sem(key,size,IPC_CREAT | IPC_EXCL | 0666);
}
key_t Get_key()
{
    return Get_shm_key();
}
void Deleteshm(int shmid)
{
    int n = shmctl(shmid, IPC_RMID, nullptr);
    if(n < 0)
    {
        cout << "Delete fail " << strerror(errno) << endl;
    }
}
void Debugshm(int shmid)
{
    struct shmid_ds c;
    int n = shmctl(shmid, IPC_STAT, &c);
    if(n < 0)
    {
        cout << "Delete fail " << strerror(errno) << endl;
    }
    cout << c.shm_atime << endl;
    cout << c.shm_dtime << endl;
    cout << c.shm_perm.__key << endl;
}
void* Attachshm(int shmid)
{
    void* addr = shmat(shmid, nullptr, 0);
    if((long long int)addr == -1)
    {
        cout << "shmat fail " << endl; 
        return nullptr;
    }
    return addr;
}
void Dis_attachshm(void* ptr)
{
    int n = shmdt(ptr);
    if(n < 0)
    {
        cout << "shmdt fail " << strerror(errno) << endl; 
    }
} 
