#include <iostream>
using namespace std;
/*1. Написать программу для хранения в битовом поле информации о
конфигурации компьютера. Например: Корпус AT – 0, ATX – 1; Видео на борту
– 0, карта – 1 и так далее.*/

struct conf
{
    unsigned bit: 2;
};
/*я хотел сделать нормальную структуру, а не одно битовое поле, но по условиям задачи надо использовать одно
битовое поле для всех характеристик*/

int main()
{
    conf comp;
    char *string[]= {"Нет", "Да"};
    comp.bit=1;
    cout <<"\tДвухядерный процессор "<<string[comp.bit]<<endl;
    comp.bit=2;//у меня две планки по два гб
    cout<<"\tОперативная память количество плат "<<comp.bit<<" по 2гб"<<endl;
    comp.bit=1;
    cout<<"\tДисплей "<<string[comp.bit]<<endl;
    comp.bit=1;
    cout<<"\tТачпад "<<string[comp.bit]<<endl;
    comp.bit=1;
    cout<<"\tДискретное видео "<<string[comp.bit]<<endl;
    comp.bit=0;
    cout<<"\tИнтегрированное видео "<<string[comp.bit]<<endl;
    return 0;
}
