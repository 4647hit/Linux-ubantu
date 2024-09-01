#include "Comm.hpp"
#include "pipe.hpp"
int main()
{
    //以只读方式打开管道文件
    int fd = open(Path,O_WRONLY);
    key_t key = Get_key();
    //获取shmid
    int shmid = Get_shm(key,4096);
    //挂接
   char* ptr = (char*)Attachshm(shmid);
    memset(ptr,0, 4096);
    for(char e = 'a'; e <= 'z'; e++)
    {
        write(fd,&e,sizeof(char));
        sleep(1);
        cout << "Client say : " << e << endl;
        ptr[e-'a'] = e; 
    }
    sleep(1);
    //去关联
    Dis_attachshm((void*)ptr);
    close(fd);
    return 0;
}