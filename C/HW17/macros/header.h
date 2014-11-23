#ifndef HEADER_H
#define HEADER_H
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define PARS_CHARS(A) { char string[]="is cool!"; char t=A; if(t=='5'){ fout<<string; } else{ fout<<t;} } //парсит один единственный символ
#define PARS_STRING(A) { char str2[]="is cool!\n"; char *str1=A; if(strstr(str1, "5")) strcpy(str1, str2); }//парсит всю строку целиком
#define PARS_CHARACTERS(A) { char str2[]="is cool!\n"; char *str1=A; if(strstr(str1, "5")) strcat(str1, str2); }

using namespace std;
void puts();
void gets();
#endif // HEADER_H
