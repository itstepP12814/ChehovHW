#include <iostream>
using namespace std;
/*1. Через указатели на указатели посчитать сумму двух чисел и записать в
третье*/
int main()
{
    int a,b,c, *pa, *pb, *pc, *ppa, *ppb, *ppc;
    a=15;
    b=18;
    pa=&a;
    pb=&b;
    pc=&c;
    /*я не совсем понимаю что от меня тут хотят, но по идее они хотят указатель на указатель*/
    ppa=&*pa;
    //а можно сдлеать просто ppa=pa;
    ppb=&*pb;
    ppc=&*pc;
    *ppc=*ppa+*ppb;
    cout <<*ppc<< endl;
    return 0;
}
