#include "header.h"
void bubble(int array[], int size)
{
    int x;
    for(int i=0; i<size; ++i)
    {
        for(int j=size-1; j>i; --j)
        {
            if(array[j-1]>array[j])
            {
                x=array[j-1];
                array[j-1]=array[j];
                array[j]=x;
            }
        }
    }
}
