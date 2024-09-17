#include <iostream>
#include <unistd.h>
#include <signal.h>


void handler(int signum)
{

    while (true)
    {
        sigset_t pending;
        sigemptyset(&pending);
        sleep(1);
        sigpending(&pending);
        std::cout << "pending bitmap : ";
        for (int i = 31; i > 0; i--)
        {
            if (sigismember(&pending, i))
            {
                std::cout << "1";
            }
            else
            {
                std::cout << "0";
            }
        }
        std::cout << std::endl;
    }
}
int main()
{
    struct sigaction act, oact;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    act.sa_handler = handler;
    sigaction(2, &act, &oact);
    while (1)
        sleep(1);
    return 0;
}
// void Print(sigset_t &pe)
// {
//     std::cout << "pending map: ";
//     for (int i = 31; i >= 1; i--)
//     {
//         if (sigismember(&pe, i))
//         {
//             std::cout << "1";
//         }
//         else
//         {
//             std::cout << "0";
//         }
//     }
//     std::cout << std::endl;
// }
// int main()
// {
//     sigset_t block, oblock;
//     sigemptyset(&block);
//     sigemptyset(&oblock);
//     for(int i = 1; i < 32; i++)
//     {
//         sigaddset(&block, i);
//     }
//     sigaddset(&block, 2);
//     int n = sigprocmask(SIG_BLOCK, &block, &oblock);
//     if (n == 0)
//     {

//         while (true)
//         {
//             sigset_t pending;
//             sigemptyset(&pending);
//             sigpending(&pending);
//             sleep(1);
//             Print(pending);
//         }
//     }
//     return 0;
// }
