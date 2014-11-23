#include "header.h"
int main()
{
    const int size = 5;
    int array[size];
    //int array[size]= {0,5,1,7,1};
    cout<<"\t\tИсходный массив\n";
    generator( array, size);
    display(array, size);
    cout<<"\t\tМетод выбора\n";
     selection(array, size);
     display(array, size);
     generator(array, size);
     cout<<"\t\tПузырьковая сортировка\n";
     bubble(array, size);
     display(array, size);
     generator(array,size);
     cout<<"\t\tСортировка вставками\n";
     insertion(array,size);
     display(array, size);
     generator(array, size);
     cout<<"\t\tБыстрая сортировка\n";
     fast(array,size);
     display(array, size);
     generator(array, size);
     cout<<"\t\tСортировка слиянием\n";
     int l=0;
     int r=size;
     merge_sort(array, l, r);
     display(array, size);
     generator(array, size);
    cout<<"\t\tПирамидная сортировка\n";
    sort_pyramid(array, size);
    display(array, size);
    generator(array, size);
    cout<<"\t\tЕще одна сортировка\n";
    unknown_sort(array, size);
    display(array, size);
    generator(array, size);
    return 0;
}
