#include "functions.h"
void generator(int *m, int size)
{
    srand(time(NULL));
    for(int i=0; i<size; ++i, ++m)
    {
        *m=rand()%100;
    }
}
void generator1(int *m, int size)
{
    srand48(time(NULL));
    for(int i=0; i<size; ++i, ++m)
    {
        *m=rand()%100;
    }
}
