#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//тут я объявляю прототипы функций;
int main()
{
    int a=1;
    while(a==1)
    {
        int ost_dig, ost_sys;
        int i=0;
        const int sz=20;
        char array[sz];
        int digit, system;
        char choice;
        cout<<"\t\tКулькулятор системы счисления"<<endl;
        cout<<"\tВы хотите сами выбрать число и систему счисления сами,"<<endl<<"\tили они должны быть выбраны компьютером?\n";
        cout<<"\tY если хотите ввести число сами"<<endl<<"\tN. если оставляете выбор за компьютером\n";
        cin>>choice;
        if(choice=='Y'||choice=='y')
        {
            cout<<"\tвведите число\n";
            cin>>digit;
            cout<<"\tвведите систему счисления\n";
            cin>>system;
        }
        else
        {
            srand(time(NULL));
            digit=rand()%100+1;
            system=rand()%35+2;
            cout<<"\tЧисло и система счисления выбраны компьютером"<<endl;
            cout<<"\tчисло = "<<digit<<endl;
            cout<<"\tсистема счисления = "<<system<<endl;
        }
        int dig=digit;
        int sys=system;
        while(dig!=0) //этот цикл записывает значения в массив
        {
            ++i;
            ost_dig=dig/sys;//целое число при делении десятичного на систему счисления
            ost_sys=dig%sys;//остаток от десятичного числа
            dig=ost_dig;//работаем с копией dig которую мы переписали до запуска предудущего цикла
            if(ost_sys>9)
            {
                array[i]='A'+ost_sys-10;//заполняет массив буквами от А до максимальной в данной системе счисления.
            }
            else
            {
                array[i]='0'+ost_sys;//заполняет массив символами цифр от 0 до 9
            }
        }
        cout<<"\tрезультат = ";
        for(int j=i; j>0; --j)  //а этот выводит значения в обратном порядке
        {
            cout<<array[j];
        }
        cout<<endl;
        cout<<"\tХотете попробовать снова? Нажмите Y или N"<<endl;
        cin>>choice;
        if(choice=='Y'||choice=='y')
        {
            a=1;
        }
        else
        {
            a=0;
        }
    }
    return 0;
}
