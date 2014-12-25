#include "MonoList.h"

MonoList::MonoList() {
    begin=end=NULL;
    count=0;
    //ctor
}

MonoList::~MonoList() {
    //dtor
}
void MonoList::insert(int val) {
    if(begin==NULL) {
        //для первого элемента
        begin=new item;
        begin->value=val;
        begin->next=NULL;
        end=begin;
        ++count;
    } else {
        //Если элемент не первый
        end->next=new item;
        end->next->value=val;
        end->next->next=NULL;
        end=end->next;
        ++count;
    }
}
void MonoList::insertPos(int pos, int val) {
    item* temp=begin;
    if(pos<=count) {
        for(int i=0; i<pos; ++i) {
            if(i==(pos-1) ) {
                temp->value=val;
                break;
            } else {
                temp=temp->next;
            }
        }
    }
}
void MonoList::showPos(int pos)const {
    item* temp=begin;
    if(pos<=count) {
        for(int i=0; i<pos; ++i) {
            if(i==pos-1) {
                cout<<temp->value<<endl;
            } else {
                temp=temp->next;
            }
        }
    }
}
int MonoList::search(const int srch) const {
    item* temp=begin;
    for(int i=0; i<count; ++i) {
        if(temp->value==srch) {
            return i+1;
        } else {
            temp=temp->next;
        }
    }
    return 0;
}
void MonoList::del(int pos) {
    if(pos<=count) {
        item* temp=begin;
        item* temp_pos;//Переменная для запоминания адреса элемента предыдущего, перед удаляемым
        for(int i=0; i<pos; ++i) {
            if(i==pos-2) {
                temp_pos=temp->next->next;
                delete temp->next;
                temp->next=temp_pos;
                --count;
                break;
            } else {
                temp=temp->next;
            }
        }
    }
}
void MonoList::show() const {
    item* temp=begin;
    for(int i=0; i<count; ++i) {
        {
            cout<<temp->value<<endl;
            temp=temp->next;
        }
    }
}
