#include "Tree.h"

Tree::Tree(): root(nullptr), size(0) {

    //ctor
}

Tree::~Tree() {
    delete root;
    //dtor
}

int& Tree::operator[](const string& index) {
    Item** current=&root;
    while((*current)!=nullptr) {
        if(index == (*current)->key) {
            return (*current)->value;
        }
        if(index<(*current)->key) {
            cout<< "<" <<endl;
            current=&((*current)->left);
        } else {
            cout<< ">" <<endl;
            current=&((*current)->right);
        }
    }
    (*current)=new Item(index);
    cout<< "created "<< endl;
    size++;
    return (*current)->value;
}
void Tree::show() {

}
