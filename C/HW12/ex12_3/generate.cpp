#include"functions.h"
void generateA(int *a, int size)
{
    srand(time(NULL));
    for(int i=0; i<size; ++i, ++a)
    {
        *a=rand()%10;
    }
}
void generateB(int *b, int size)
{
    srand48(time(NULL));
    for(int i=0; i<size; ++i, ++b)
    {
        *b=rand()%10;
    }
}
void generateCommon(int *a, int *b, int *ab, int size1, int size2)
{
    for(int i=0; i<size1; ++i, ++a, ++ab)
    {
        *ab=*a;
    }
    for(int j=size1; j<size1+size2; ++j, ++ab,++b)
    {
        *ab=*b;
    }
}
