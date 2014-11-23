#include "main.h"
void punkt(char* str) {
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
            if(c>=57&&c<=64||c>=33&&c<=47) str[i]=' ';
        }
    }
    strcpy(copy, buff);
}

