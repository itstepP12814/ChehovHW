#include "functions.h"
int notInclude(int commElements[], int notIncludeArray[], int array[], int sizeCE, int size)
{
    int k=0;
    int indicator;
    for(int i=0; i<size; ++i)//цикл перебирает массив А или В
    {
		indicator=1;
        for(int j=0; j<sizeCE; ++j)//цикл перебирает массив с общими элементами
        {
            if(array[i]==commElements[j])
            {
            indicator=0;
            }
        }
        if(indicator){
        notIncludeArray[k]=array[i];
        ++k;
        }
    }
    return k;
}
