#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <stdlib.h>
#include <cstring>
#define SIZE  5
using namespace std;
enum sex {male, female};
struct form
{
    char name[256];
    char surname[256];
    int age;
    sex sx;
};
form *base();
void display(form *p);
int compareAge(const void *a, const void *b);
int compareName(const void *a, const void *b);
int compareSurname(const void *a, const void *b);
int compareSex(const void *a, const void *b);
#endif // HEADER_H
