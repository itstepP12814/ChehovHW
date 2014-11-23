#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
//3. Удалить с m по n символов, перезаписать строку и показать ее на экран.
int main2();
int main()
{
    char string[100];
    int m,n;
    printf("\tВвод\n");
    gets(string);
    printf("\tвведи m\n");
    cin>>m;
    printf("\tвведи n\n");
    cin>>n;
    printf("\tВывод\n");
    while(m<n){
    string[m]='\0';
    ++m;
    }
    puts(string);
    return 0;
}

