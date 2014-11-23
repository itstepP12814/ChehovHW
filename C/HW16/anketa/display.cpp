#include "header.h"
void display(form *p)
{
    char *a[]= {"М", "Ж"};
    int s;
    for(int i=0; i<SIZE; ++i)
    {
        s=(p+i)->sx;//присваиваем числовое значение переменной для пола
        cout<<(p+i)->name<<endl;
        cout<<(p+i)->surname<<endl;
        cout<<(p+i)->age<<endl;
        cout<<a[s]<<endl;//выводим соответствующую строку
        cout<<endl;
    }
}
