#include <iostream>
using namespace std;
const int SIZE = 3;
struct  my
{
    int hour;
    int  min;
    int sec;
};
my* timeBase()
{
    my a= {11, 12, 15};
    my b= {16, 17, 18};
    my c= {19, 20, 21};
    my array[SIZE]= {a, b, c}, *p;
    p=array;
    return p;
}
int main()
{
    my* p=timeBase();
    for(int i=0; i<SIZE; ++i)
    {
        cout<<(p+i)->min<<endl;
    }
    return 0;
}
