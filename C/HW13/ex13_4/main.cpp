#include <iostream>
using namespace std;
//4. Найти заданную степень числа, пользуясь только указателями.
void calculate ( unsigned long *a, unsigned long *b, int *c);
int main()
{
    unsigned long a, b, *pa, *pb;
    int deg, *pdeg;
    pdeg=&deg;
    pa=&a;
    pb=&b;
    cout <<"\t\tВведи число\n";
    cin>>*pa;
    cout<<"\t\tВведи степень\n";
    cin>>*pdeg;
    *pb=*pa;
    calculate(&a, &b, &deg);
    cout<<*pb;
    return 0;
}
void calculate(unsigned long *a, unsigned long *b, int *deg)
{
    for(int i=1; i<*deg; ++i)
    {
    *b=*b*(*a);
    }
}
