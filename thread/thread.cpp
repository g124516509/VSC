#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
thread::id main_thread_id =this_thread::get_id();
void hello()
{
    cout<<"hello Concurrent World"<<endl;
    if(main_thread_id ==this_thread::get_id()) 
        {
        cout<<"i am the main thread"<<endl;
        }   
    else
    {
        
        cout<<"i am child thread :"<<this_thread::get_id<<endl;
    }
    
}
void pause_thread(int n)
{
    this_thread::sleep_for(chrono::seconds(n));
    cout<<"pause of "<<n<<" seconds ended"<<endl;    
}
int main()
{
    thread t(hello);
    cout<<t.hardware_concurrency()<<endl;
    cout<<"native_handle"<<t.native_handle()<<endl;
    sleep(3);
    t.join();
    thread a(hello);
    a.detach();
    thread threads[5];

    cout<<"spawning 5 threads....."<<endl;
    for(int i=0;i<5;i++)
    {
        threads[i]=thread(pause_thread,i+1);

    }
    cout << "Done spawning threads. Now waiting for them to join:\n";
    for (auto &thread : threads)
        thread.join();
    std::cout << "All threads joined!\n";



    return 0;
}