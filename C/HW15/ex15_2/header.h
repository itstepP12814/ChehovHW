#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;
int **create(int, int, int);
int questionRow(int **p, int **pp, int, int);
int questionCol(int **p, int **pp, int, int);
void display(int **p, int, int);
void shiftRowUp(int **p, int **pp, int, int, int, int);
void shiftRowDown(int **p, int **pp, int, int, int, int);
void shiftColRight(int **p, int **pp, int, int, int, int);
void shiftColLeft(int **p, int **pp, int, int, int, int);
void del(int **p, int **pp, int **ppp, int);
#endif // HEADER_H
