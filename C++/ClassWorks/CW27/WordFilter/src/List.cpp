#include "List.h"

List::List() {
    begin=nullptr;
    end=nullptr;
    //ctor
}
List::List(string str) {
    begin=nullptr;
    end=nullptr;
    s=str;
}
void List::push_front(string str) {
    if (begin == nullptr) {  // for the 1st element
        begin = new word;
        end=begin;
        begin->next = nullptr;
        begin->prev = nullptr;
    } else { // for following elements
        begin->prev = new word;
        begin->prev->prev = nullptr;
        begin->prev->next = begin;
        begin = begin->prev;
    }
    begin->wrd = str;
}
void List::push_back(string str) {
    if(end==nullptr) {
        end=new word;
        begin=end;
        end->next=nullptr;
        end->prev=nullptr;
    } else {
        end->next=new word;
        end->next->next=nullptr;
        end->next->prev=end;
        end=end->next;
    }
    end->wrd=str;
}
void List:: parser(int index) {
    word* iterator=begin;
    word* temp=nullptr;
    string s_dot=s+'.';
    if((begin->wrd==s || begin->wrd==s_dot)&&begin->next!=nullptr) {
        begin=begin->next;
        begin->prev=nullptr;
        iterator->next=nullptr;
        iterator->prev=nullptr;
        delete iterator;
        iterator=begin;
    }
    for(int i=0; i<index; ++i) {
        if(iterator->next!=nullptr) {
            iterator=iterator->next;
            if(iterator->wrd==s || iterator->wrd==s_dot) {
                if(iterator->next!=nullptr) {
                    iterator->next->prev=iterator->prev;
                    iterator->prev->next=iterator->next;
                    temp=iterator->prev;
                    iterator->next=nullptr;
                    iterator->prev=nullptr;
                    delete iterator;
                    iterator=temp;
                } else {
                    iterator->prev->next=nullptr;
                    delete iterator;
                    //cout << "end of list in parser error3" <<endl;
                }
            }
        } else {
            //cout<< "end of list error1" <<endl;
        }
    }
}
void List::show(int index) const {
    word* iterator=begin;
    if(iterator!=nullptr) {
        /**т.к в первый вывод нам будет показат iterator->next это не будет вывод первого элемента списка слов,
        а только второго и далее, поэтому я вывожу первый элемент еще до запуска цикла для вывода всех иостальных
        эл-тов. Т.к интуитивно хочется передать в функцию все количество слов, а выводить в циуле мы будем все, кроме первого
        поэтому i<index-1**/
        cout<< iterator->wrd << " ";
        for(int i=0; i<index; ++i) {
            if(iterator->next!=nullptr) {
                iterator=iterator->next;
                cout<< iterator->wrd <<" ";
            } else {
                //cout<< "list shown" << endl;
            }
        }
    } else {
        cout<< "list is empty" <<endl;
    }
}

List::~List() {
    //dtor
}
