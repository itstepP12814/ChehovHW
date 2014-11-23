#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    char *string=new char[128];
    char f;
    int i;
    printf("\tСтрока ввода\n");
    gets(string);
    printf("\tВведи искомый символ\n");
    f=getchar();
    for(i=0; i<strlen(string); ++i)
    {
        if(*(string+i)==f);
    }
    printf("\t%d", i-1);
    delete []string;
    return 0;
}
