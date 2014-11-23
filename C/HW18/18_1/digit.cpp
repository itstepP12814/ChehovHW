#include "main.h"
void digit(char* str) {
    static char copy [SIZE];
    static char buff[SIZE];
    static int count=0;
    int c;
    count++;
    strcpy(buff, str);
    if(count%2==0) {
        strcpy(str, copy);
    } else {
        for(int i=0; i<SIZE-1; ++i) {
            c=(int)str[i];
            if(c>=48&&c<=57) str[i]=' ';
        }
    }
    strcpy(copy, buff);
}

