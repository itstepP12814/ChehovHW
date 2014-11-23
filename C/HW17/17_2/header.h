#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
const int NUM_OF_STUDENTS = 7;//количество студентов
const int NUM_OF_SUBJECTS = 4;//количество предметов в базе
struct exam
{
    char name[256];
    int group;
    unsigned derm: 1;//дерматовенерология
    unsigned epid: 1;//эпдемка
    unsigned gig: 1;//гигиена
    unsigned c: 1;//зачет по си
};
enum {DERM, EPID, GIG, C};
exam* base();
void display(exam*);
void completeAllExam(exam*);
void displayAll(exam*);
void debtorGroupDisp(exam*);
void debtorSubjectsDisp(exam*);
#endif // HEADER_H
