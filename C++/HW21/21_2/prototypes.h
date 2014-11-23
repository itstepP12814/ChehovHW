#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "person.h"
using namespace std;
/*в данной прггармме можно было обойтись одним хедером, и засунуть в него прототипы всех функций и все подключаемые библотеки,
но я решил вынести функции вне класса в отдельный файл,а уже в него включить хедер для класса, просто для удобства, правда я не уверен
что это правильный подход к арзитектуре программы*/
void inputAllData(Person*, int);
void editEmploye(Person* , int);
void printEmploye(Person* , int);

#endif // PROTOTYPES_H_INCLUDED
