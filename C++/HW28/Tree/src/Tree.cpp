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
            current=&((*current)->left);
        } else {
            current=&((*current)->right);
        }
    }
    (*current)=new Item(index);
    size++;
    return (*current)->value;
}
void Tree::iterator() {
    //попытка написать итератор
    Item** current=&root;
    Item** previous=&(*current);
    while((*current)!=nullptr) {
        if((*current)->left!=nullptr) {
            previous=&(*current);
            current=&((*current)->left);
        } else {
            cout<< (*current)->key<< " " << (*current)->value <<endl;
            current=&(*previous);
            if((*current)->right!=nullptr){
                previous=&(*current);
                current=&((*current)->right);
            }
        }
    }
}
void Tree::showTree(Item* node){
        if(node!=nullptr){
            showTree(node->left);
            cout << node->key << " " << node->value << endl;
            showTree(node->right);
        }
    }
