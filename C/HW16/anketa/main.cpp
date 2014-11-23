#include "header.h"
/*нам нужно сделать прогарммку, которая с помощью функции qsort сортирует анкеты сотрудников*/
int main()
{
    form *p=base();//запись указателя на массив с данными анкет
    int a;
    cout<<"\tВыберите по какому криетирб будем сортировать анкеты\n";
    cout<<"\t1 - по имени 2 - по фамилии 3 - по возрасту\n\t4 - по полу 5 - выход\n";
    cin>>a;
    switch(a)
    {
    case 1:
        qsort(p, SIZE, sizeof(form), compareName);
        display(p);
        break;
    case 2:
        qsort(p, SIZE, sizeof(form), compareSurname);
        display(p);
        break;
    case 3:
        qsort(p, SIZE, sizeof(form), compareAge);
        display(p);
        break;
    case 4:
        qsort(p, SIZE, sizeof(form), compareSex);
        display(p);
        break;
    case 5:
        break;
    }
    return 0;
}
