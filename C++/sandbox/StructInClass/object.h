#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
#include <stdlib.h>
using namespace std;
struct stru {
    int a;
    int b;
    int c;
};

class object {
public:
    object();
    object(int, int, int);
    object(const object&);
    void operator=(const object&);
    object operator+(const object&);
    void show()const;
    virtual ~object();
    stru* s;
};

#endif // OBJECT_H
