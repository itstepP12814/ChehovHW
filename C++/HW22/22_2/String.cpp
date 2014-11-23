#include "String.h"
#include <iostream>
#include <cstring>
using namespace std;
String::String()
{
}

String::String(char* str)
{
    int length=strlen(str);
    s =(char*) malloc(length*sizeof(char));
    strcpy(s,str);
    //ctor
}
String::String(const String& str)
{
    int length=strlen(str.s);
    s = (char*) malloc(length*sizeof(char));
    strcpy(s,str.s);
    //ctor
}

String::~String()
{
    //dtor
}
