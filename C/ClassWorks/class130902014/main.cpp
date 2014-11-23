/* qsort example */
/*Использование функции qsort из библиотеки*/
//домашка
/*найти тройку в массиве, и посчитать сколько там всего троек*/
/*написать функцию, которая возвращает время предыдущего запуска функция time, это упражнение на использование статических переменных static int lol*/
#include "header.h"
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
int main ()
{
    srand(time(NULL));
    const int N=100;
    int values[N];
    for(int i=0 ; i<N; ++i)
    {
        values[i]=rand()%(N/10)+1;
    }
    int n;
    qsort (values, 100, sizeof(int), compare);
    for (n=0; n<100; n++)
        printf ("%d ",values[n]);
	int needle=3;
	binarySearch(values, N, needle);
    return 0;
}
