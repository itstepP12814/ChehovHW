#include "search_end_sorting.h"
int reshuffle(int array[], int size)
{
    int a;
    int x;
    for(int m=0; m<size; m++)//перетасовка ячеек. Не совсем понимаю зачем это делать, если массив итак заполняется каждый раз рандомно
    {
        a=rand()%size;//рандом выбирает ячейки от 0 до 9 включительно
        x=array[m];
        array[m]=array[a];
        array[a]=x;
    }
    return array[size];
}

int generate_array(int array[], int size)
{
    for(int i=0; i<size; ++i)
    {
        array[i]=rand()%20+1;
    }
    return array[size];
}
