#include <iostream>
#include <windows.h>

using namespace std;

HANDLE hMutex = NULL;

DWORD WINAPI Fun(LPVOID lpParamate)
{
    for(int i=0;i<10;i++)
    {
        WaitForSingleObject(hMutex,5000);
        cout<<"A thread Fun Display"<<i<<endl;
        Sleep(100);
        ReleaseMutex(hMutex);
    }
    return 0L;
}
int main()
{
    HANDLE hThread = CreateThread(NULL,(SIZE_T)200,Fun,NULL,0,NULL);
    hMutex = CreateMutex(NULL,FALSE,"screen");
    CloseHandle(hThread);
    for(int i=0;i<10;i++)
    {
        WaitForSingleObject(hMutex,5000);
        cout<<"MAIN thread Display"<<i<<"\n";
        Sleep(500);
        ReleaseMutex(hMutex);
    }
}