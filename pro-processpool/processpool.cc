#include<iostream>
#include<unistd.h>
#include<cstdlib>
#include<vector>
using namespace std;
class Channel
{
public:
    Channel(int wfd,pid_t sub_fd,const std::string&name)
    :wfd(wfd)
    ,_sub_process_id(sub_fd)
    ,name(name)
    {}
    void Debug()
    {
        cout<< " wfd :" << wfd ;
        cout<< " _sub_process_id :" << _sub_process_id;
        cout<< "name :" << name <<endl;
    }

private:
    int wfd;
    pid_t _sub_process_id;
    string name;
};

enum
{
    UsageError = 1,
    ArgError,
    PipeError
};
void usage(const std::string& proc)
{
    cout << "usage: " << proc << "subprocess-num" << endl; 

}
int main(int argc,char* argv[])
{
    if(argc != 2)
    {
        usage(argv[0]);
        return UsageError;
    }
    int sub_process_num = std::stoi(argv[1]);
    if(sub_process_num <= 0)
    {
        return ArgError;
    }
    //创建进程和管道
    vector<Channel> channels;
    for(int i = 0; i < sub_process_num;i++)
    {
        int pipefd[2]{0};//管道数组清零
        int n = pipe(pipefd);
        if(n < 0)
        {
            return PipeError;
        }
        pid_t id = fork();
        if(id == 0)
        {
            //子进程 -> read
            close(pipefd[1]);
            // 执行的任务
            exit(0);

        }
        string cname = "channel - "+ to_string(i);
        //父进程
        close(pipefd[0]);
        channels.push_back(Channel(pipefd[1],id,cname));
    }
    //控制子进程
    for(auto & channel :  channels)
    {
        channel.Debug();
    }
    //回收子进程
    return 0;
}