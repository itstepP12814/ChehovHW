#ifndef ARRAY_H
#define ARRAY_H
#include <stdio.h>
#include <stdlib.h>
class Array {
public:
    Array();
    ~Array();
    void setSizeUpTo(int);
    int& operator[](int);
    const int print(int i) const {
        return array[i] ;
    };
private:
    size_t size;
    int* array;
};

#endif // ARRAY_H
