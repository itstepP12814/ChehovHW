#ifndef TREE_H
#define TREE_H
#include <string.h>
#include <iostream>
using namespace std;


struct item {
    string val;
    int key;
    item* left;
    item* right;
    item* next;
    item* prev;
};

class Tree
{
    public:
        Tree();
        virtual ~Tree();
    protected:
    item* root;
};

#endif // TREE_H
