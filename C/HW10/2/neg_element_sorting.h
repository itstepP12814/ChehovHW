#ifndef NEG_ELEMENT_SORTING_H
#define NEG_ELEMENT_SORTING_H
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
int negativeElementSorting( int a[], int b);//в прототипе обязательно надо указать именно массив а не просто а
void display(int a[], int b);
int negativeElementSorting( int array[], int size)
{
    int i;
    int j;
    int x;
    int right;
    int left;
    for(int k=0; k<size; ++k)
    {
        if(array[k]<0)//цикл перебирает числа слева напарво до первого отрицательного числа
        {
            left=k;//записываем номер ячейки крайнего левого числа
            break;
        }
    }
    for(int m=size; m>0; --m)//перебираем числа справа нелево до первого отрицательного числа
    {
        if(array[m]<0)
        {
            right=m;//записываем номер ячейки крайнего правого отрицательного числа
            break;
        }
    }
    for(i=left+1; i<right; ++i)/*цикл соритрует числа по возрастанию
     между крайними отрицательными, при этом НЕ ВКЛЮЧАЯ сами крайние числа в сортировку*/
    {
        x=array[i];
        for(j=i+1; j<right; ++j)
        {
            if(array[j]<x)
            {
                x=array[j];
                array[j]=array[i];
                array[i]=x;
            }
        }
    }
    return array[size];
}
void display(int array[],int size){
 for(int i=0; i<size; ++i)
    {
        array[i]=rand()%41-20;//задает значения от -20 до +20;
        cout<<array[i]<<" ";
    }
}
#endif // NEG_ELEMENT_SORTING_H
