#include "header.h"
void inputTime(my_tm* p)
{
	//функция установки времени
	int h;
    cout<<"\tВведите часы\n";
	cin>>h;
	p->hour=h;
	cout<<"\tВведите минуты\n";
    cin>>h;
    p->min=h;
    cout<<"\tВведите секунды\n";
    cin>>h;
    p->sec=h;
}
void returnInputTime(my_tm* p)
{
    cout<<"\tУстановленное время\n";
    char string[40];
    tm time;
    tm* timeinfo=&time;
    timeinfo->tm_hour=p->hour;
    timeinfo->tm_min=p->min;
    timeinfo->tm_sec=p->sec;
    char* format="\t%H : %M : %S";
    strftime(string, 40, format, timeinfo);//функция переписывания текущего системного времени из структуры tm в обычную строку
    cout<<string<<endl;
}

