#include <iostream>
#include <stdio.h>
using namespace std;

double division(int a, int b);

int main(int argc, char *argv[])
{
    cout << "Value of __LINE__ : " << __LINE__ << endl;
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;
    while (true)
    {
        int x = 50, y = 0;
        double z = 0;
        cin >> x >> y;
        try
        {

            z = division(x, y);
            cout << x << "/" << y << "=" << z << endl;
        }
        catch (const char *msg)
        {
           cout<<msg<<endl;
        }
        catch(int m)
        {
            cerr<<m<<endl;
        }
   }

    return 0;
}
double division(int a, int b)
{
   if( b == 0 )
   {
      throw  "分母不能为0！";
   }
   return ((double)a/b);
}