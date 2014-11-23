#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
int insertProbel()
{
    char s[]="Talin";
    int len=strlen(s);
    char *a=(char*) malloc((len*2+1)*sizeof(char));
    char *b=NULL;
    b=(char*)realloc(a, (len*2+1));
    if(b!=NULL)
    {
        int j=0;
        for(int i=0; i<len*2; ++i)
        {
            a[i+1]=' ';
        }
        cout<<a;
    }
    else
    {
        cout<<"error\n";
    }
    return 0;
}
