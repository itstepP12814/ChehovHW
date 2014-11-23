#ifndef HEADER_H
#define HEADER_H
#include <iostream>
using namespace std;
int **create(int, int);
void insertRow(int **p, int, int, int);
void selection(int **p, int, int);
void display(int **p, int, int);
void insertCol(int **p, int, int, int);
void deleteMatrix(int **p, int);
void copyMatrix(int **p, int **pp, int, int);
void insertCol(int **p, int, int, int);
#endif // HEADER_H
