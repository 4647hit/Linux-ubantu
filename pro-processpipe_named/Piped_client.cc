#include"Comm.hpp"


int main()
{
    Fifo fifo(Path);
    int rfd = open(Path,O_RDONLY);
    if(rfd < 0)
    {
        cout << "open file failed, cause by " << strerror(errno) << endl; 
    }
        char inbuffer[1024] = {0};
    while(true)
    {
        char inbuffer[1024] = {0};
        ssize_t n = read(rfd,inbuffer,sizeof(inbuffer) - 1);
        if(n > 0)
        {
            cout << "server said: " << inbuffer << endl;
        }
        else if(n == 0)
        {
            cout << "server has done" << endl;
            break;
        }
        else
        {
            cout << "read failed, cause by " << strerror(errno) << endl;
            break;
        }
    }
    close(rfd);
    return 0;
}
