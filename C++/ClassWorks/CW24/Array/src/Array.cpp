#include "Array.h"

Array::Array(): size(1), array(NULL) {
    setSizeUpTo(1);
    //ctor
}

Array::~Array() {
    //dtor
}

void Array::setSizeUpTo(int i) {
    while(i>=size) {
        size*=2;
    }
    array=(int*)realloc(array, size*sizeof(int));
}
int& Array::operator[](int i) {
    setSizeUpTo(i);
    return array[i];
}
