#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class I>
void sorting (I arr[], I size, I chf)
{
    I i;
    I x;
    I j;
    for(i=0; i<size; ++i)
    {
        x=arr[i];//присваивание x значения из ячейки i
        for(j=i+1; j<size; ++j)
        {
            if(chf==1)
            {
                if(arr[j]<x)
                {
                    x=arr[j];//x - изменяется в него записывается значение из ячейки j
                    arr[j]=arr[i];//в ячейку j записывается бывшее значение из ячейки i,
                    arr[i]=x;//а в ячейку i переписывается значение из ячейки j.
                }
            }
            else
            {
                if(arr[j]>x)
                {
                    x=arr[j];//x - изменяется в него записывается значение из ячейки j
                    arr[j]=arr[i];//в ячейку j записывается бывшее значение из ячейки i,
                    arr[i]=x;//а в ячейку i переписывается значение из ячейки j.
                }

            }
        }
    }
    for(int k=0; k<size; k++)
    {
        cout<<arr[k]<<endl;
    }
    if(chf==1)
    {
        cout<<"\tмассив был отсортирован по возрастанию"<<endl;
    }
    else
    {
        cout<<"\tмассив отсортирован по убыванию"<<endl;
    }
}
void input(int array[], int size){
 for(int i=0; i<size; ++i)
    {
        cin>>array[i];
    }
}
#endif // SORTING_H
