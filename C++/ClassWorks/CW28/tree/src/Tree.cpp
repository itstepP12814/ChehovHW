#include "Tree.h"

Tree::Tree()
{
    root=nullptr;
    //ctor
}

Tree::~Tree()
{
    delete root;
    //dtor
}

int& Tree::operator[](const string& index)
{
    Item** current= &root;
    //берем адрес ячейки памяти в которой храниться казатель рут
    while( (*current)!=nullptr)
    {
        if((*current)->key==index)
        {
            return (*current)->value;
        }
        if(index<(*current)->key)
        {
            current=&((*current)->left);
            /*в куррент записываем адрес ячейки памяти в которой храниться казатель
            лефт, самого объекта по указателю лефт может быть а может и не быть, мы запи
            сываем только адрес указателя лефт, выполняя операция взятия адреса*/
        }

    }
    (*current)=new Item(index);
}
