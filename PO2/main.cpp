#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

float maxim(float a, float b, float c,)
{
    d=a;
    if (b>a)
    {
        d=b;
    }
    if (c>b)
    {
        d=c;
    }
return (d);
}
float maxim(float a,float b,float c, float d, float e)
{
    e=a;
    if (b>a)
    {
        e=b;
    }
    if (c>b)
    {
        e=c;
    }
    if (d>c)
    {
        e=d;
    }
return (e);
}
int main( )
{
cout << "Maximul e" << maxim(100,200,300)<<endl;
cout << "Maximul e" << maxim(5,7,9,11.4 )<<endl;
system ("pause");
}
