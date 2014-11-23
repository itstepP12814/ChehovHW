#include "mathx.h"


int gcd(int a, int b)
{
    if(!b)
    {
        return a;
    }
    while(a%b)
    {
        int c=a%b;
        a=b;
        b=c;
    }
    return b;
}

int lcm(int a, int b)
{
    return a*(b/gcd(a,b));
}
