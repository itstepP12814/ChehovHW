#ifndef EQUATION_H
#define EQUATION_H
#include <iostream>
#include <math.h>
using namespace std;
template <typename I> I equation(I a, I b);
template <typename I> I equation(I a, I b, I c);

template <typename I> I equation(I a, I b)
{
    I x;
    if(a!=0)
    {
        x=-b/a;
        if(x==-0) //добавил потому что в результат выводится при a!=0&&b==0 в результат пишется -0, выглядит некрасиво;
        {
            x=0;
        }
        cout<<"\t\tрезультат: x = "<<x<<endl;
    }
    if(a==0&&b==0)
    {
        cout<<"\t\tуравнение имеет множество решений"<<endl;
    }


    if(a==0&&b!=0)
    {
        cout<<"\t\tуравнение не имеет решений"<<endl;
    }
    return 0;
}
template <typename I> I equation(I a, I b, I c)
{
    I Descr;
    I x1;
    I x2;
    Descr=(b*b)-(4*a*c);
    if(Descr>0)
    {
        x1=(-b+sqrt(Descr)/2*a);
        x2=(-b-sqrt(Descr)/2*a);
        cout<<"\t\tпервый корень = "<<x1<<endl;
        cout<<"\t\tвторой корень = "<<x2<<endl;
    }
    if(Descr==0)
    {
        x1=-b/2*a;
        cout<<"\t\tединственный корень x = "<<x1<<endl;
    }
    if(Descr<0)
    {
        cout<<"\t\tнет корней"<<endl;
    }
    return 0;
}


#endif // EQUATION_H
