#include "ContactTree.h"

ContactTree::ContactTree() : root(NULL), sizeOfTree(0) {
}


ContactTree::~ContactTree() {
}
int& ContactTree::operator[](const int index) {
    Subscriber** current = &root;
    Subscriber* pr = NULL;
    while ((*current) != NULL) {
        pr = (*current);
        if ((*current)->name == index) {
            return (*current)->number;
        }
        if (index < (*current)->name) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    (*current) = new Subscriber(index);
    (*current)->parent = pr;
    ++sizeOfTree;
    return (*current)->number;
}
void ContactTree::showFromLeft(Subscriber* node) {
    if (node != NULL) {
        if (node->left) {
            showFromLeft(node->left);
        }
        print(node);
        if (node->right) {
            showFromLeft(node->right);
        }
    }
}
ContactTree::Subscriber* ContactTree::max(Subscriber* node) {
    if (node != NULL) {
        while (node->right != NULL) {
            node = node->right;
        }
        return node;
    } else return NULL;
}
ContactTree::Subscriber* ContactTree::min(Subscriber* node) {
    if (node != NULL) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    } else return NULL;
}
ContactTree::Subscriber* ContactTree::next(Subscriber* node) {
    if (node != NULL && node->right != NULL) {
        return min(node->right);
    } else return NULL;
}
ContactTree::Subscriber* ContactTree::prev(Subscriber* node) {
    if (node != NULL&&node->left != NULL) {
        return max(node->left);
    } else return NULL;
}

ContactTree::Subscriber* ContactTree::searchByName(const int index) {
    Subscriber** current = &root;
    int checker = 0;
    while ((*current) != NULL) {
        if ((*current)->name == index) {
            cout << "found!" << endl;
            print(*current);
            checker = 1;
            return *current;
        }
        if (index < (*current)->name) {
            current = &((*current)->left);
        } else {
            current = &((*current)->right);
        }
    }
    if (!checker) {
        cout << "nothing found" << endl;
        return NULL;
    } else return *current;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ContactTree::deleteContact(const int index) {
    Subscriber* deletedContact = searchByName(index);//удаляемый контакт
    Subscriber* minFromRightBranch = NULL;//узел следующий по индексу за удаляемым, проще говоря это самый "левый" узел в правой от удаляемого ветки

    if(!deletedContact) { //найден ли вообще удаляемый узел
        cout<< "error" <<endl;
        return;
    }
    //случай 1 Когда удаляемый элемент просто лист
    if (deletedContact->left == NULL && deletedContact->right == NULL) {
        if (deletedContact == deletedContact->parent->left) {
            //переписываем родителю указатели на путсые в зависимости от того с какой стороны стоял лист
            deletedContact->parent->left = NULL;
            delete deletedContact;
            //мы удалили структуру по указателю, но в самом указателе оказался мусор, принулдительно Выходим из функции
            return;
        } else {
            deletedContact->parent->right = NULL;
            delete deletedContact;
            return;
        }
    }
    /*2 случай когда справа и слева есть ветки т.к если два предыдущих условия пройдены значит у нас есть две полноценные ветки
    мы не будем структурно разрущать элемент, а найдем следующий по возрастанию по индексу элемент, перепишем данные из него и удалим "следующий"
    так делается, потому что у этого следующего будет либо оддна дочерняя ветка справа либо вообще ни одной
    проверка условия (deletedContact->right!=NULL && deletedContact->left!=NULL) особо ненужна, т.к в данном случае мы уверены что узел точно не пустой
    и что в нем точно две ветки
    мы точно знаем что у него не будет ветки слева, но может быть ветка справа, а может и не быть;*/
    if(deletedContact->right!=NULL && deletedContact->left!=NULL) {
        minFromRightBranch=next(deletedContact);//находим следующий по индексу элемент из правой ветки, это будет самый "левый элемент"
        if(minFromRightBranch) {
            deletedContact->name=minFromRightBranch->name;
            deletedContact->number=minFromRightBranch->number;
            if(minFromRightBranch->right!=NULL) {
                //если вправа есть ветка проверяем каким этот элемент стоит от роидителя, т.к самый "левый" может стоять справа, если ветка идет отвесно вправо
                //по сути в этом случае "самый левый" будет дочерним от удаляемого
                if(minFromRightBranch==minFromRightBranch->parent->left) {
                    minFromRightBranch->parent->left=minFromRightBranch->right;
                    minFromRightBranch->right->parent=minFromRightBranch->parent;
                    delete minFromRightBranch;
                } else {
                    minFromRightBranch->parent->right=minFromRightBranch->right;
                    minFromRightBranch->right->parent=minFromRightBranch->parent;
                    delete minFromRightBranch;
                }
            } else {
                //если "следующий" просто лист
                if(minFromRightBranch==minFromRightBranch->parent->left) {
                    minFromRightBranch->parent->left=NULL;
                } else {
                    minFromRightBranch->parent->right=NULL;
                }
                delete minFromRightBranch;
            }
        }
        return;
    }
    //3 если слева от удаляемого узла ничего нет
    if( deletedContact->right!=NULL && deletedContact->left==NULL ) {
        //Проверяем с какой стороны удаляемый стоит от своего родителя
        if(deletedContact==deletedContact->parent->right) {
            deletedContact->parent->right=deletedContact->right;
            deletedContact->right->parent=deletedContact->parent;
        } else {
            deletedContact->parent->left=deletedContact->right;
            deletedContact->right->parent=deletedContact->parent;
        }
        delete deletedContact;
    } else {
        //4 случай когда справа от удаляемого узла ничего нету
        //проверяем с какой стороны удаляемый стоит от родителя
        if(deletedContact==deletedContact->parent->right) {
            deletedContact->parent->right=deletedContact->left;
            deletedContact->left->parent=deletedContact->parent;
        } else {
            deletedContact->parent->left=deletedContact->left;
            deletedContact->left->parent=deletedContact->parent;
        }
        delete deletedContact;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ContactTree::print(Subscriber* node) {
    if (node->parent) {
        cout << "parent " << node->parent->name << endl;
    }
    cout << "name " << node->name << endl;
    cout << "number " << node->number << endl << endl;
}

ContactTree::Subscriber* getRoot(const ContactTree& A) {
    return A.root;
}
