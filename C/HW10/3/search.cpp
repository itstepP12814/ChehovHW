#include "search_end_sorting.h"
int linear_search(int array[], int size, int key)
{
    int position=-1;//задаю значение по умолчанию, если позиция не найдена прогармма сортировки не запустится
    for(int i=0; i<size; ++i) //Перебираем перетасованный массив в поисках искомого числа
    {
        if(array[i]==key)
        {
            position=i;//запоминаем позицию искомого числа
            return position;
        }
    }
    return position;//если позиция не изменилась, то возвращаем -1
}
