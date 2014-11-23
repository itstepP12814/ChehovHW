#include "header.h"
/*3. Создать битовое поле для хранения времени (часы, минуты, секунды,
миллисекунды). Написать функции для установки и получения времени в(из)
битовое(-го) поле(-я).*/
int main()
{
    int a;
    my_tm my_time;
    my_tm* p=&my_time;
    void (*menu[])(my_tm*) = {timeReturn, inputTime, returnInputTime, showAll};
    while(1)
    {
        cout<<"\t1 - показать текущее время\n\t2 - установить время самому\n\t3 - показать установленное время\n";
        cin>>a;
        cin.ignore();
        if(a>=0&&a<=4)
            menu[a-1](p);
        else return 0;
    }
    return 0;
}
