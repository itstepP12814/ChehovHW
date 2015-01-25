#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class Tree {
protected:
    class Item {
    public:
        Item(const string& key_): left(nullptr), right(nullptr), next(nullptr), prev(nullptr), key(key_) {}
        ~Item() {
            delete left;
            delete right;
            delete next;
            delete prev;
        }
        const string key;
        int value;
        Item* left;
        Item* right;
        Item* next;
        Item* prev;
    };
    Item* root;
    int size;
public:
    Tree();
    ~Tree();
    int& operator[](const string&);
    void iterator();
    void showTree(Item*);
    Item* getRoot(){return root;}
};

#endif // TREE_H
