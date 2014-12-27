#ifndef TREE_H
#define TREE_H
#include <string.h>
#include <iostream>
using namespace std;


class Tree
{
public:
    Tree();
    virtual ~Tree();
    int& operator[](const string&);
    class Item;
    class Iterator
    {
    public:
        Iterator ():current(nullptr) {};
        Iterator& operator++();
        int& operator*();
        bool operator==(const Iterator& another);
        ~Iterator() {}
    private:
        Item** current;
    };
    Iterator begin(){
    }
    Iterator end() {return iterator(); }
private:

    class Item
    {
    public:
        Item (const string& key_): left(nullptr), right(nullptr), key(key_) {}
        ~Item() {}
        const string key;
        int value;
        Item* left;
        Item* right;
    };

    Item* root;
};

#endif // TREE_H
