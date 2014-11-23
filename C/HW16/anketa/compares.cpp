#include "header.h"
/*
Пояснение для меня, чтоб незабыть
int values[] = { 40, 10, 100, 90, 20, 25 };
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
compare - Функкция сравнения двух элементов массива, т.к функция принимает указатели любого типа нам необходимо в ее теле преобразовать указатели до
нужного типа;
int compar (const void* p1, const void* p2);
<0	The element pointed by p1 goes before the element pointed by p2
0	The element pointed by p1 is equivalent to the element pointed by p2
>0	The element pointed by p1 goes after the element pointed by p2
int main ()
{
  int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
values - поинтер на первый элемент массива
6 - количество элементов
sizeof - размер нашей структуры или типа передаваемого массива
 */
int compareAge(const void *a, const void *b)
{
    const struct form A=*(const struct form*)a;
    /*в скобках мы делаем явное преобразование указателя из типа воид
    в тип const struct form*, а потом говорим компилятору, чтобы он присвоил именно такой тип указателю а
    Затем мы записываем в переменную A, значение на которое ссылается преобразованный указатель a*/
    const struct form B=*(const struct form*)b;
    return (A.age-B.age);
}
int compareName(const void *a, const void *b)
{
    const struct form A=*(const struct form*)a;
    const struct form B=*(const struct form*)b;
    return strcmp(A.name,B.name);
    /*т.к мы работаем на этот раз не с числами, а с чарами,нам нужна функция для сравнения строк,
    которая после того как отработает, вернет соответсвующий инт*/
}
int compareSurname(const void *a, const void *b)
{
    const struct form A=*(const struct form*)a;
    const struct form B=*(const struct form*)b;
    return strcmp(A.surname,B.surname);
}
int compareSex(const void *a, const void *b)
{
    const struct form A=*(const struct form*)a;
    const struct form B=*(const struct form*)b;
    return (A.sx-B.sx);
}
