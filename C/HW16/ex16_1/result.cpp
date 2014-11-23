#include "header.h"
void result(video *p)
{
    /*//заводим массивы, который будут соответсвовать смысловому описания для, констант из перечислений*/
    char* genre[]= {"Комедия","Фэнтези","Фантастика"};
    char* rate[]= {"Плохо", "Нормально", "Хорошо"};
    int g=p->gnr;//присваиваем переменным числовые значения из перечислений жанра
    int r=p->rt;//рейтинга
    cout<<"\tНазвание: "<<p->title<<endl;
    cout<<"\tРежжисер: "<<p->direct<<endl;
    cout<<"\tЖанр: "<<genre[g]<<endl;//выводим значения из массивов
    cout<<"\tРейтинг: "<<rate[r]<<endl;
    cout<<"\tСтоимость: "<<p->cost<<"\n\n";
}
void dispAll(int size, video *p)
{
    for(int i=0; i<size; ++i)
    {
        cout<<"\t№ "<<i+1<<endl;
        result(p+i);
    }
}
