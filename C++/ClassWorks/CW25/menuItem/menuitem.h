#ifndef MENUITEM_H
#define MENUITEM_H
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class MenuItem {
public:
    MenuItem();
    virtual ~MenuItem();
    virtual void operator()()=0;//=0 означает, что у метода нету тела
};

class GavItem:  public MenuItem {
public:
    GavItem();
    ~GavItem();
    virtual void operator()() {
        printf("\tGav\n");
    }
};
class KukuItem: public MenuItem {
public:
    KukuItem();
    ~KukuItem();
    virtual void operator()() {
        printf("\tKukareku\n");
    }
};
class ExitItem: public MenuItem {
public:
    ExitItem();
    ~ExitItem();
    virtual void operator()() {
        printf("\tExit\n");
    }
};
#endif // MENUITEM_H
