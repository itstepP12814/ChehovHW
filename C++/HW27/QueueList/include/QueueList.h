#ifndef QUEUELIST_H
#define QUEUELIST_H
#include <iostream>
using namespace std;

template <typename T> struct Element{
    T val;
    Element* next;
    Element* prev;
};

template <typename T> class QueueList
{
    public:
        QueueList();
        void add(T);
        virtual ~QueueList();
    protected:
    int count;
    Element<T>* begin;
    Element<T>* end;
};
template <typename T> QueueList <T>::QueueList()
{
    begin=end=NULL;
    count=0;
    //ctor
}

template <typename T> QueueList <T>::~QueueList()
{
    //dtor
}


template <typename T> void QueueList <T>::add(T  val){
    cout<<val<<endl;
    cout<<sizeof(T)<<endl;
}


#endif // QUEUELIST_H
