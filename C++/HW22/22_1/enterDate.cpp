#include "date.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void  Date::enterDate(char* str) {
    int res = sscanf(str,"%d.%d.%d",&day,&month,&year);
    if ((res == 0) || (day<1) || (day>31)) {
        cout<<"\tОшибка в номере дня\n";
        exit(0);
    }
    if ((res == 1) || (month<1) || (month>12)) {
        cout<<"\tОшибка в номере месяца\n";
        exit(0);
    }
    if ((res == 2) || (year<1) || (year>9999)) {
        cout<<"\tОшибка в номере года\n";
        exit(0);
    }
}
