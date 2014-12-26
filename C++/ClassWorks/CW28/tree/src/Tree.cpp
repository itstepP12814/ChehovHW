#include "Tree.h"

Tree::Tree() {
    root=nullptr;
    //ctor
}

Tree::~Tree() {
    //dtor
}

void Tree::addItem(int k, string str) {
    static Item** current=&root;
    if(current==nullptr) {
        //если элемент нулевой то мы его создаем
        (*current)=new Item;
        (*current)->key=k;
        (*current)->val=str;
        (*current)->left=nullptr;
        (*current)->right=nullptr;
        (*current)->next=nullptr;
        (*current)->prev=nullptr;
    }
    if(k<(*current)->key) {
        //Если ключ меньше чем в текущем эл-те, идем налево
        (*current)->left=new Item;
        (*current)->left->key=k;
        (*current)->left->val=str;
        (*current)->left->left=nullptr;
        (*current)->left->right=nullptr;
        //пока не будем программировать указатели на некст и превьюс
        (*current)->left->next=nullptr;
        (*current)->left->prev=nullptr;
        (*current)=(*current)->left;
    } else {
        if((*current)->key>k) {
            //если ключ больше текущего - идем направо
            (*current)->right=new Item;
            (*current)->right->key=k;
            (*current)->right->val=str;
            (*current)->right->left=nullptr;
            (*current)->right->right=nullptr;
            //
            (*current)->right->next=nullptr;
            (*current)->right->prev=nullptr;
        } else {
            //если ключ равен текущему - перезаписываем текущий
            (*current)->val=str;
        }
    }
}
