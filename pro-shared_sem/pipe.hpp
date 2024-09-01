#include<iostream>
#include<cstring>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <unistd.h>
using namespace std;

#define Path "./fifo"
#define Mode 0666
class Fifo
{
public:
    Fifo(string _path): path(_path)
    {
        int n = mkfifo(path.c_str(),Mode);
        if(n == 0)
        {
            cout << "mkfifo success" << endl;
        }
        else
        {
            cout << "mkfifo fail ， fail cause by " << strerror(errno) << endl; 
        }

    }
    ~Fifo()
    {
        int n = unlink(path.c_str());
        if(n == 0)
        {
            cout << "unlink success" << endl;
        }
        else
        {
            cout << "unlink fail ， fail cause by " << strerror(errno) << endl; 
        }

    }
private:
    string path;
};
