#include "search_end_sorting.h"
int sorting(int array[], int size, int position)
{
    srand(time(NULL));
    int x;
    if(position!=-1)//сортировка массива до и после искомого числа
    {
        for(int i=0; i<position; ++i)
        {
            x=array[i];
            for(int j=i+1; j<position; ++j)//сортирует числа по убыванию ДО искомого
            {
                if(array[j]>x)
                {
                    x=array[j];
                    array[j]=array[i];
                    array[i]=x;
                }
            }
        }
        for(int l=position+1; l<size; ++l)//сортирует по возрастанию ПОСЛЕ искомого
        {
            x=array[l];
            for(int o=l+1; o<size; ++o)
            {
                if(array[o]<x)
                {
                    x=array[o];
                    array[o]=array[l];
                    array[l]=x;
                }
            }
        }
    }
    return array[size];
}


