#include <iostream>
using namespace std;
/*5. Произвести, используя указатель на указатель проверку на нуль при
делении*/
void check(double *a, double *b);
int main()
{
    double a, b, c, *pa, *pb, *pc, null, *pnull, *ppnull;
    pa=&a;
    pb=&b;
    pc=&c;
    null=0;
    pnull=&null;
    ppnull=&(*pnull);//По идее от меня хотят указатель на указатель. Это вроде он
    cout<<"\t\tВведите делимое\n";
    cin>>*pa;
    cout<<"\t\tВведите делитель\n";
    cin>>*pb;
    if(*pb!=*ppnull)//испольЫзую указатель на указатель. Правда смысл для меня потерян.
    {
        *pc=*pa/(*pb);
        cout<<*pc;
    }
    else
    {
        cout<<"\t\tОшибка деления на 0\n";
    }
    return 0;
}
