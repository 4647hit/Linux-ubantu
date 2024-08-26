#include"Comm.hpp"

int main()
{
    key_t k = Get_key();
    int shmid = Creat_sem(k, 1024);
    cout << shmid << endl;
    return 0;
}