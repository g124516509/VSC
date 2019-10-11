#include <iostream>
using namespace std;

double division(int a, int b);

int main(int argc, char *argv[])
{
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
            cerr << msg << endl;
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
      throw "function error";
   }
   return ((double)a/b);
}