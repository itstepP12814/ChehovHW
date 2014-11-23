#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
struct dfn
{
    char name[128];
    char value[128];
    int value_lenght;//длина строки со значением, она нам понадобиться для замены макроса на значение
};
void gets();
#endif // HEADER_H
