#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
struct word {
    string wrd;
    word* next;
    word* prev;
};

class List {
public:
    List();
    List(string);
    virtual ~List();
    void push_front(string);
    void push_back(string);
    void show(int)const;
    void parser(int);
protected:
    word* begin;
    word* end;
    string s;
};

#endif // LIST_H
