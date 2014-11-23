//домашка
/*найти тройку в массиве, и посчитать сколько там всего троек*/
/*написать функцию, которая возвращает время предыдущего запуска функция time, это упражнение на использование статических переменных static int lol*/
#include "header.h"
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
    /* как я понял, функция принимает два указателя любого типа, и во время возврата они преобразует эти любые указатели в интовые
    в то же время она возвращает разницу между объектами, на которые ссылаються эти уже интовые указатели*/
}
int main()
{
    srand(time(NULL));
    const int N=100;
    int array[N];
    int needle, a=1;
    for(int i=0; i<N; ++i) array[i]=rand()%9+1;
    qsort (array, N, sizeof(int), compare);
    while(a)
    {
        cout<<"\tВедите число от 1 до 10, которое требуется найти\n";
        cin>>needle;
        if(needle>=1&&needle<=10)
        {
            binarySearch(array, N, needle);
            break;
        }
        else cout<<"\tВведите корректное число\n";
    }
    for(int i=0; i<N; ++i) cout<<array[i];
    return 0;
}
