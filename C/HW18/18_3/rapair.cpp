#include "main.h"
void repair(char* str, char* str_buf,int len) {
//убираем все ненужные нам знаки из строки, проме цифр и знака действия
    int c, j=0;
    for(int i=0; i<len; ++i) {
        c=str[i];
        if(c>=42&&c<=57) {
            str_buf[j]=str[i];
            ++j;
        }
    }
}
