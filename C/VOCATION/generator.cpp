#include "header.h"
void generator( int array[], int size)
{
    srand (time(NULL));
    for (int i=0; i<size; ++i)
    {
        array[i]=rand()%11;
    }
}
void display(int array[], int size)
{
    for(int i=0; i<size; ++i)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
