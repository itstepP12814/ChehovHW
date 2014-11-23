#include "main.h"
/*суть алгоритма в том, чтобы введенный символ не попадал в определнный диапазон для филтрации
по таблице анси. Может быть есть более рациональный сопособ, чтобы можно было обойтись без точных числовых
указаний символов, но я его не придумал =( */
void latin(char* str) {
    static char copy [SIZE];//массив для хранения копии оригинала
    static char buff[SIZE];//буферный массив
    static int count=0;
    /*счетчик запуска функции, при первом запуске массив переданный массив будет изменен, при втором, нам необходимо отменить
    предыдущее изменение, то есть переписать массив из существуещей копии, т.е каждый четный раз массив будет перезаписываться
    из харнимой внутри функции копии, при каждом нечетном запуске исходный массив будет изменяться согласно правилам фильтрации*/
    int c;//переменная для получения кодировки символа по таблице анси
    count++;
    strcpy(buff, str);//копирование исходного массива в буфер
    if(count%2==0) {
        //если нужно отменить фильтрацию(каждый четный запуск), переписываем массив из уже существующей копии
        strcpy(str, copy);
    } else {
        for(int i=0; i<SIZE-1; ++i) {
            c=(int)str[i];
            if(c>=65&&c<=122) str[i]=' ';
        }
    }
    strcpy(copy, buff);//переписываем исходный массив из буфера в копию.
}
