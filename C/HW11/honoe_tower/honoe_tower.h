#ifndef HONOE_TOWER_H
#define HONOE_TOWER_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*
1)для перемещения а дисков требуется перместить а-1 дисков на временную пирамиду,
2)переместить последний диск на нужную пирамиду
3)переместить а-1 дисков с временной на нужную парамиду
П.С. алгоритм был честно подсмотрен на хабре и главным образом на вики.
П.П.С если бы я сказал что мне тут все совершенно понятно, я бы соврал, наверное это надо просто взять и понять=(
*/
void honoe_tower(int disk_number, int from_pyramid,int temp_pyramid,int to_pyramid)
{
    if(disk_number!=0)
    {
        honoe_tower(disk_number-1,from_pyramid,to_pyramid, temp_pyramid);//тут идет пошаговый реверс временной пирамиды с той, на которую мы хотим переместить
        cout<<"\tперемещаю диск "<<disk_number<<" с "<<from_pyramid<<" пирамиды на "<<to_pyramid<<" пирамиду\n";
        honoe_tower(disk_number-1,temp_pyramid, from_pyramid, to_pyramid);// тут тоже той с которой будем перемещать и временной.
    }
}
void switcher(int disks, int to_pyramid)
{
    int temp_pyramid;//номер временной пирамиды
    int from_pyramid=1;//изначально будем перемещать с 1 пирамиды
    if(to_pyramid==2)//если перемещать нужно на 2 пирамиду, то временной будет 3
    {
        temp_pyramid=3;
    }
    else//иначе - вторая
    {
        temp_pyramid=2;
    }
    honoe_tower(disks, from_pyramid, temp_pyramid, to_pyramid);
}

#endif // HONOE_TOWER_H
