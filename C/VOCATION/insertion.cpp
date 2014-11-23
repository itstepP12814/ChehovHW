#include "header.h"
void unknown_sort(int array[], int size)//вот эту сортировку я написал случайно
{
    int x;
    for(int i=0; i<size; ++i)
    {
        for(int j=i+1; j<size; ++j)
        {
            x=array[i];
            if(array[j]<x)
            {
                array[i]=array[j];
                array[j]=x;
            }
        }
    }
}
void insertion(int array[], int size)
{
    int x;
    for(int i=0; i<size; ++i)
    {
        x=array[i];
        for(int j=i-1; j>=0&&array[j]>x; --j)
        {
            array[j+1]=array[j];
            array[j]=x;
        }
    }
}
