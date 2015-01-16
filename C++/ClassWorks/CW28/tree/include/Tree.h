#ifndef TREE_H
#define TREE_H
#include <string.h>
#include <iostream>
using namespace std;
///щрн яелокнбши мепюанвхи йнд, пюанвхи б оюойе я днлюьйюлх

class Tree {
private:
    class Item {
    public:
        Item (const string& key_): left(nullptr), right(nullptr), key(key_) {}
        ~Item() {}
        const string key;
        int value;
        Item* left;
        Item* right;
    };

    Item* root;
public:
    Tree();
    ~Tree();
    int& operator[](const string&);

    class Iterator {
    public:
        Iterator (): current(nullptr) {};
        ///Iterator& operator++();
        ///int& operator*();
        ///bool operator==(const Iterator& another);
        ~Iterator() {}
    private:
        Item* current;
    };
    Iterator begin() {
    }
    Iterator end() {
        return Iterator();
    }
};

#endif // TREE_H
