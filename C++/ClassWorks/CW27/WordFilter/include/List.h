#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstring>
using namespace std;
struct word{
    string wrd;
    word* next;
    word* prev;
};

class List
{
    public:
        List();
        virtual ~List();
        void push_front(string);
    protected:
    word* begin;
    word* end;
};

#endif // LIST_H
