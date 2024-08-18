#include"Comm.hpp"
int main()
{

    int wfd = open(Path, O_WRONLY);
    if(wfd < 0)
    {
        cout << "open file failed, cause by " << strerror(errno) << endl; 
    }
    while(true)
    {
        string inbuffer;
        cout << "please input your information: ";
        std::getline(cin,inbuffer);
        if(inbuffer == "quit") break;
        ssize_t n = write(wfd,inbuffer.c_str(),inbuffer.size());
        if(n < 0)
        {
            cout << "write failed, cause by " << strerror(errno) << endl;
            break;
        } 
    }
    close(wfd);

    return 0;
}