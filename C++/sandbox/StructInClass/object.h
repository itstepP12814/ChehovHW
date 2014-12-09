#ifndef OBJECT_H
#define OBJECT_H
#include <iostream>
struct stru {
    int a;
    int b;
    int c;
};

class object {
public:
    object();
    virtual ~object();
    stru* s;
};

#endif // OBJECT_H
