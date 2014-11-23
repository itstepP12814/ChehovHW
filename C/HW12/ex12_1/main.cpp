#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void showElements(int *m, int size)
{
    for(int i=0; i<size; m++, i++)
    {
        cout<<*m<<" ";
    }
    cout<<"\n\n";
}
void reverseElements(int *m, int size)
{
    int x, y, temp;
    for(int i=0; i<size; m++, i++)
    {
        x=*m;//запись в x значения элемента с индексом m
        y=*(m+1);//запиьс в у значения элемента с индексом m+1
        if(i%2==0)//если элемент четный
        {
            temp=x;//переписываем значение элемента с индексом м
            *m=y;//элементу с индексом м присвоить значение из элемента с индексом м+1
            *(m+1)=temp;//элементу с индексом м+1 присвоить значение элемента с индексом м, который уже переписан во временную переменную
        }
    }
}
int main()
{
    const int size=20;
    int array[size];
    srand(time(NULL));
    for(int i=0; i<size; ++i)
    {
        array[i]=rand()%100;
    }
    cout<<"перовначальный массив\n";
    showElements(array,size);//показ массива на экран
    reverseElements(array, size);//вызов функции перетасовщика
    cout<<"измененный массив\n";
    showElements(array,size);/*показ измененного массива на экран.*/
    return 0;
}
