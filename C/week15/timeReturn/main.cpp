#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
//функция должна возвращать время своего прудыдущего запуска
time_t timeReturn()
{
    /*time_t - это по сути лонг*/
    static time_t t, previous_time;//время первого запуска
    previous_time=t;
    t=time(NULL);
    return previous_time;
    /*инициализируем время текущего запуска, которое собстно при последуюшем запуске и выдаст
    нам время уже не текущего, а предыдущего запуска. Вот такая вот логика*/
}
int main()
{
    int a, choice;
    cout<<"\tПри каждом запуске функция будет возвращать нам\n";
    cout<<"\tвремя своего предыдущего запуска(кроме самого первого,которое равно 0)\n";
    while(a)
    {
        cout<<"\t1 - запуск функции, 2 - выход\n";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"\tПредыдущий запуск был\n"<<timeReturn()<<endl;
            break;
        case 2:
            break;
        default:
            cout<<"\tВведите верную опцию\n";
            break;
        }
    }
    return 0;
}
