#include "header.h"
//2. Написать примитивный калькулятор, пользуясь только указателями.
int main()
{
    cout<<"\t\tКалькулятор\n";
    double a, b, c;
    char ch;
    cout<<"\tВведите первое число\n";
    cin>>a;
    cout<<"\tВведите действие + - * / S-для корня, Q-для квадрата\n";
    cin>>ch;
    if(ch=='S'||ch=='s'||ch=='Q'||ch=='q')
    {
        calc(&ch, &a, &b, &c);
        cout<<"\tРезультат\n";
        cout<<c;
        return 0;
    }
    else
    {
        cout<<"\tВедите второе число\n";
        cin>>b;
        calc(&ch, &a, &b, &c);
        cout<<"\tРезультат\n";
        cout<<c;
        return 0;
    }
}
