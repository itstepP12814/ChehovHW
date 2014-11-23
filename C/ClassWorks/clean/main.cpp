#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "clean.h"

using namespace std;

int main()
{
    cout << "\t\t\t\tEnter something" << endl;
    cout<<"\t\tfor clean terminal enter \"clr\" on keyboard"<<endl;
    while (getchar() != EOF)
    {
        if (getchar()=='c'&&getchar()=='l'&&getchar()=='r')//
        {
            clean_commline();
        }
    };
    return 0;
}
