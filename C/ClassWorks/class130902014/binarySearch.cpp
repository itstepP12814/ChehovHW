#include "header.h"
using namespace std;
void binarySearch(int array[], int size, int needle)
{
    int i=0, j=size-1 , m;
    if(array[i]>needle||array[j]<needle) printf("\tЭлемент отсутствует в массиве найден\n");
    if(array[i]==needle) printf("%d", "\tЭлемент найден в позиции\n", i);
    if(array[j]==needle) printf("%d","\tЭлемент найден в позиции\n", j);
    else
    {
        while((j-i)>0)
        {
            m=(j+i)/2;
            if(array[m]==needle) {
            printf("%d", "\tЭлемент найден в позиции\n", m);
            break;
            }
            if(array[m]>needle) j=m;
            else i=m;
        }
    }
    if(array[m]!=needle) printf("%d","\tЭлемент не найден\n", m);
}
