#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include "rounding.h"
using namespace std;

int main()
{
    //setprecision(8) - 8 знаков после запятой
    char choice='Y';
    while (choice=='Y'||choice=='y')
    {
        srand(time(NULL));
        /*double a=(1+rand()%1000)*pow(0.1, (1+rand()%5));берем случайное число от 1 до 999 и умножаем на случайное число от
        0,1 до 0,0005. Но работало оно  правильно, но выдавало иногда не совсем то что требовалось в задании*/
        double a=355.0/113.0;//и я взял число пи с точностью до 6 знаков после запятой
        int n;
        cout<<"\t\tесть число Пи с точностью до 6 знаков после запятой, но"<<endl;
        cout<<"\t\tможно указать другое количество знаков будет после запятой"<<endl;
        cout<<"\t\tвведи количество знаков после запятой"<<endl;
        cin>>n;
        rounding(n, a);
        cout<<"\t\tпопробовать снова? Y - если да"<<endl;
        cin>>choice;
    }
    return 0;
}
