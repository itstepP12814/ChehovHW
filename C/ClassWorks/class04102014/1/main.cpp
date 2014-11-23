#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "itoa.h"
#include <math.h>
/*
функция itoa;
установить 2й бит
установить iй бит
сбросить 3й бит
инфертировать iбит
если iй бит
если 1й бит установлен - сказать hallo
*/
using namespace std;

int main()
{
    char buff[128];
    int a, x=4, i;
    //x=4 т.к  мы устанавливаем 3й бит
    cout<<"введите число\n";
    scanf("%d", &a);
    cout<<"двоичное представление\n";
    itoa(a, buff, 2);
    cout<<buff<<endl;

    cout<<"установить 2-й бит\n";
    a=a|x;
    cout<<"x=4"<<endl;
    itoa(x, buff,2);
    cout<<buff<<endl;
    itoa(a, buff, 2);
    cout<<buff<<endl;

    cout<<"установить i й бит\n";
    cin>>i;
    x=1<<i;
    a=a|x;
    itoa(a, buff, 2);
    cout<<buff<<endl;

    cout<<"сбросить третий бит"<<endl;


    return 0;
}
