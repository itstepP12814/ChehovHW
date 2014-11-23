#include "header.h"
form *base()
{
    form a= {"Валерий", "Августинович", 28, male};
    form b= {"Фродо", "Бэггинс", 37, male};
    form c= {"Маргарита", "Джедааевна", 95, female};
    form d= {"Наталья", "Прокопьевна", 44, female};
    form e= {"Владимир", "Ленский", 32, male };
    form array[SIZE]= {a,b,c,d,e};
    form *p;
    p=array;
    return p;
}
