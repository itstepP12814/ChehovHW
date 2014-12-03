#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;
String String::operator*(const String& str) const
{
    int i=0, j=0, k=0;
    char res_str[32]= {};
    for(i=0; i<strlen(str.s); i++)
    {
        for(j=0; j<strlen(s); ++j)
        {
            if(str.s[i]==s[j])
            {
                res_str[k]=s[j];
                ++k;
                break;
            }
        }
    }
    String result(res_str);
    return result;
}
void String::print()const
{
    cout<<s<<endl;
}
