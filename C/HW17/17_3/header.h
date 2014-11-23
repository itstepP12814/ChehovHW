#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int SIZE = 3;
struct  my_tm
{
	unsigned hour: 8;
    unsigned min: 8;
    unsigned sec: 8;
};
void timeReturn(my_tm*);
void inputTime(my_tm*);
void returnInputTime(my_tm*);
void showAll(my_tm*);
void show(my_tm*, int);
my_tm* timeBase();
#endif // HEADER_H
