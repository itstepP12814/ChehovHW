#ifndef MONOLIST_H
#define MONOLIST_H
#include <iostream>
#include <stdlib.h>
using namespace std;
struct item {
    int value;
    item* next;
};
class MonoList {
public:
    MonoList();
    void show() const;
    void insert(int);
    void insertPos(int, int);
    void showPos(int) const;
    int search(const int)const;
    void del(int);
    virtual ~MonoList();
protected:
    item* begin;
    item* end;
    int count;
};

#endif // MONOLIST_H
