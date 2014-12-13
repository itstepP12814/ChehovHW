#include "List.h"

List::List()
{
    begin=nullptr;
    end=nullptr;
    //ctor
}
void List::push_front(string str){
    if(end==nullptr){
        end=new word;
        begin=end;
        begin->next=nullptr;
        begin->prev=nullptr;
        begin->wrd=str;
    } else {
        end->next=new word;
        end->next->next=nullptr;
        end->next->prev=end;
        end->prev=begin;
        end->prev->next=end;
        end->prev->prev=nullptr;
        end->wrd=str;
    }
}

List::~List()
{
    //dtor
}
