#include <iostream>
#include <math.h>
#include "equation.h"

using namespace std;

int main()
{
    char big_choice ='Y';
    while (big_choice=='Y'||big_choice=='y')
    {
        cout << "\t\tсейчас мы будем вспоминать алгебру, выбери тип уравнения" << endl;
        cout<<"\t\t1 - линейное уравнение			2 - квадратное"<<endl;
        char choice;
        double a;
        double b;
        double c;
        cin>>choice;
        if(choice=='1')
        {
            cout<<"\t\tлинейное уравнение вида: ax+b=0"<<endl;
            cout<<"\t\tвведи а"<<endl;
            cin>>a;
            cout<<"\t\ta = "<<a<<endl;
            cout<<"\t\tвведи b"<<endl;
            cin>>b;
            cout<<"\t\tb = "<<b<<endl;
            equation(a, b);
            cout<<"\t\tпопробовать снова? Y - если да, или любую другую кнопку если нет"<<endl;
            cin>>big_choice;
        }
        else
        {
            cout<<"\t\tквадратное уравнение вида ax^2 + bx + c = 0"<<endl;
            cout<<"\t\tвведи а"<<endl;
            cin>>a;
            cout<<"\t\ta = "<<a<<endl;
            cout<<"\t\tвведи b"<<endl;
            cin>>b;
            cout<<"\t\tb = "<<b<<endl;
            cout<<"\t\tвведи c"<<endl;
            cin>>c;
            cout<<"\t\tc = "<<c<<endl;
            equation(a, b, c);
            cout<<"\t\tпопробовать снова? Y - если да, или любую другую кнопку если нет"<<endl;
            cin>>big_choice;
        }
    }
    return 0;
}
