#include <iostream>
using namespace std;
//3. Найти факториал числа, пользуясь только указателями.
int main()
{
    int a, size, *pa, *psize;
    a=0;
    size=10;
    pa=&a;
    psize=&size;
    for(int i=1; i<=*psize; ++i)
    {
        if(*pa==0) //по договоренности факториал 0!=1;
        {
            *pa=1;
            cout<<*pa<<endl;
        }
        *pa=*pa*i;
        cout<<*pa<<endl;
    }
    return 0;
}
