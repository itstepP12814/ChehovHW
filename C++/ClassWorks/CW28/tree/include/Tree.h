#ifndef TREE_H
#define TREE_H
#include <string.h>
#include <iostream>
using namespace std;


struct Item {
    string val;
    int key;
    Item* left;
    Item* right;
    Item* next;
    Item* prev;
};

class Tree {
public:
    Tree();
    virtual ~Tree();
    void addItem(int, string);
protected:
    Item* root;
};

#endif // TREE_H
