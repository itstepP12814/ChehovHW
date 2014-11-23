#include "main.h"
void kiril(char* str) {
    /*у меня не получилось вытянуть из кириллических букс их кодировочный номер, прием работает со всем кроме кириллицы,
    пробовал использовать setlocale(LC_CTYPE, "rus"); не помогло, использовал строку как массив для сравнения*/
    static char copy [SIZE];
    static char buff[SIZE];
    char ABC[]="АаБбВвГгДдЕеЁёЖжЗзИиЙйКкЛлМмНнОоПпРрСсТтУуФфХхЦцЧчШшЩщЪъЫыЬьЭэЮюЯя";
    static int count=0;
    char a, b;
    count++;
    strcpy(buff, str);
    if(count%2==0) {
        strcpy(str, copy);
    } else {
        for(int i=0; i<SIZE-1; ++i) {
            for(int j=0; j<66; j++) {
                if(ABC[j]==str[i]) str[i]=' ';
            }
        }
    }
    strcpy(copy, buff);
}
