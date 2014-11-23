#include "header.h"
void repair_pyramid(int array[], int size, int i)
{
    int l=(2*i)+1;//левый и
    int r=(2*i)+2;//правый потомки
    int large=i;
    int temp;
    if(l<=size-1&& array[i]<array[l]) large=l;
    if(r<=size -1&& array[large]<array[r]) large=r;
    if(large!=i) //если произошел обмен меняем местакми array[large] и array[i]
    {
        temp=array[i];
        array[i]=array[large];
        array[large]=temp;
        repair_pyramid(array, size, large);
    }
}
void build_pyramid(int array[], int size)
{
    for(int i=size/2; i>=0; --i)
    {
        repair_pyramid(array,size, i);
    }
}
void sort_pyramid(int array[], int size)
{
    int temp;
    int large=0;//первый элемент максимальный
    build_pyramid(array, size);
    for(int i=size-1; i>=1; --i)
    {
        temp=array[i];
        array[i]=array[large];
        array[large]=temp;
        --size;
        repair_pyramid(array, size, large);
    }
}
