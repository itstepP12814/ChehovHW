#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class Array {
public:
    Array(int);
    Array( const Array&);
    virtual ~Array();
    /*тут и далее довольно извращенно, можно было использовать обычный realloc,   и сделать методы void но
       захотелось сделать вовзрат временного объекта по ссылке с "заменой" хڅڅپригинального*/
    void operator+(int);
    void operator-(int);
    void operator++();
    void operator--();
    int operator[](int)const;
    void print()const;

protected:
    int count;
    int* p;
    int size;
};

#endif // ARRAY_H
