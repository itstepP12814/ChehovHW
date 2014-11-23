#include "header.h"
void fast(int array[],  int size)
{
    int i=0;
    int j=size;
    int p=array[size/2];
    int temp;

    while(i<=j)
    {
        while(array[i]<p) i++;
        while(array[j]>p) j--;
        if(i<=j)
        {
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
            i++;
            j--;
        }
    }
    if(j>0) fast(array, j);
    if(i<size) fast(array+i,size-i);
}
