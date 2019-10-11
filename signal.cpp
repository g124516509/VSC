#include <csignal>
#include <iostream>
#include <Windows.h>
using namespace std;
void signalHandle(int signum)
{

    cout<<"Interrupt signal("<<signum<<")received"<<endl;
   // exit(signum); 

}
int main()
{
    int i=0;
    signal(SIGINT,signalHandle);

    while(++i)
    {
        cout<<"Going to sleep"<<endl;
        Sleep(1000);
        if(i==3)
        {
            raise(SIGINT);
            break;
        }
    }
    cout<<"end of progrem"<<endl;
    return 0;
}