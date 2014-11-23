#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
/*
2. Показать на экран с m по n символов строки, введенной пользователем и
записать данный отрезок в другой массив. (m и n также вводятся
пользователем)
*/
int main()
{
    int m,n;
    char string[100];
    char string2[200];
    int i=0;
    int k=0;
    printf("\tВвод\n");
    gets(string);
    printf("\tвведи m\n");
    cin>>m;
    printf("\tвведи n\n");
    cin>>n;
    printf("\tВывод\n");
    while(m<n-1)
    {
        cout<<string[m];
        string2[i]=string[m];
        ++m;
        ++i;
    }
    cout<<endl;
    for(;;)
    {
        cout<<string2[k];
        if(string[k]=='\0') break;
        ++k;
    }
    return 0;
}
