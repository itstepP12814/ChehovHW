#ifndef ROLL_H
#define ROLL_H
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

class Roll {
public:
    Roll();
    virtual ~Roll();
    char rotateRoll(int);
    void showRoll() const;
protected:
    int size;
    char symb [5]= {'\1','\3','\4','\5','\6'};
};

#endif // ROLL_H
