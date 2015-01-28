#include "ContactTree.h"

ContactTree::ContactTree() : root(NULL), sizeOfTree(0)
{
}


ContactTree::~ContactTree()
{
}
int& ContactTree::operator[](const int index){
	Subscriber** current = &root;
	Subscriber* pr = NULL;
	while ((*current) != NULL){
		pr = (*current);
		if ((*current)->name == index){
			return (*current)->number;
		}
		if (index < (*current)->name){
			current = &((*current)->left);
		}
		else {
			current = &((*current)->right);
		}
	}
	(*current) = new Subscriber(index);
	(*current)->parent = pr;
	++sizeOfTree;
	return (*current)->number;
}
/*
void ContactTree::editNumber(const string& index, const string& newNumber){
	Subscriber** current = &root;
	int checker = 0;
	while ((*current) != NULL){
		if ((*current)->name == index){
			(*current)->number = newNumber;
			checker = 1;
			break;
		}
		if (index < (*current)->name){
			current = &((*current)->left);
		}
		else {
			current = &((*current)->right);
		}
	}
	if (!checker) cout << "nothing found" << endl;
}
void ContactTree::editName(const string& index, const string& newName){
	Subscriber** current = &root;
	int checker = 0;
	while ((*current) != NULL){
		if ((*current)->name == index){
			(*current)->name = newName;
			checker = 1;
			break;
		}
		if (index < (*current)->name){
			current = &((*current)->left);
		}
		else {
			current = &((*current)->right);
		}
	}
	if (!checker) cout << "nothing found" << endl;
}
ContactTree::Subscriber* ContactTree::searchByName(const string& index){
	Subscriber** current = &root;
	int checker = 0;
	while ((*current) != NULL){
		if ((*current)->name == index){
			cout << "found!" << endl;
			print(*current);
			checker = 1;
			return *current;
		}
		if (index < (*current)->name){
			current = &((*current)->left);
		}
		else {
			current = &((*current)->right);
		}
	}
	if (!checker) {
		cout << "nothing found" << endl;
		return NULL;
	}
	else return *current;
}
void ContactTree::searchByNumber(const string& num, Subscriber* node){
	if (node != NULL){
		searchByNumber(num, node->left);
		if (node->number == num){
			cout << "found!" << endl;
			print(node);
		}
		searchByNumber(num, node->right);
	}
}
*/

void ContactTree::showFromLeft(Subscriber* node){
	if (node != NULL){
		if (node->left){
			showFromLeft(node->left);
		}
		print(node);
		if (node->right){
			showFromLeft(node->right);
		}
	}
}
void ContactTree::showFromRight(Subscriber* node){
	if (node != NULL){
		showFromRight(node->right);
		print(node);
		showFromRight(node->left);
	}
}

ContactTree::Subscriber* ContactTree::max(Subscriber* node){
	if (node != NULL){
		while (node->right != NULL){
			node = node->right;
		}
		return node;
	}
	else return NULL;
}
ContactTree::Subscriber* ContactTree::min(Subscriber* node){
	if (node != NULL){
		while (node->left != NULL){
			node = node->left;
		}
		return node;
	}
	else return NULL;
}
ContactTree::Subscriber* ContactTree::next(Subscriber* node){
	if (node != NULL && node->right != NULL){
		return min(node->right);
	}
	else return NULL;
}
ContactTree::Subscriber* ContactTree::prev(Subscriber* node){
	if (node != NULL&&node->left != NULL){
		return max(node->left);
	}
	else return NULL;
}

ContactTree::Subscriber* ContactTree::searchByName(const int index){
	Subscriber** current = &root;
	int checker = 0;
	while ((*current) != NULL){
		if ((*current)->name == index){
			cout << "found!" << endl;
			print(*current);
			checker = 1;
			return *current;
		}
		if (index < (*current)->name){
			current = &((*current)->left);
		}
		else {
			current = &((*current)->right);
		}
	}
	if (!checker) {
		cout << "nothing found" << endl;
		return NULL;
	}
	else return *current;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ContactTree::deleteContact(const int index){
	//Важно понять что мы не удаляем структурно "удаляемый узел", мы перезаписываем значения в нем, но сохраняем связи

	Subscriber* deletedContact = searchByName(index);//удаляемый контакт
	Subscriber* minFromRightBranch = NULL;//узел следующий по индексу за удаляемым, проще говоря это самый "левый" узел в правой от удаляемого ветки
	Subscriber* maxFromLeftBranch = NULL;//узел предыдущий по индексу перед удаляемым, это будет самый "правый" узел в левой от удаляемого ветке

	//случай если просто лист, лист - это узел у которого нету ни  одного потомка
	if (deletedContact){
		if (deletedContact->left == NULL && deletedContact->right == NULL){
			if (deletedContact == deletedContact->parent->left){
				//переписываем родителю указатели на путсые в зависимости от того с какой стороны стоял лист
				deletedContact->parent->left = NULL;
				delete deletedContact;
				//мы удалили структуру по указателю, но в самом указателе оказался мусор, принулдительно Выходим из функции
				return;
			}
			else {
				deletedContact->parent->right = NULL;
				delete deletedContact;
				return;
			}
		}
	}

	//случай если у удаляемого узла есть ветка справа, то на место удаляемого подставляем следующий по индексу узел, при этом есть ли слева ветка мы не учитываем
	if (deletedContact != NULL && deletedContact->right != NULL){
		minFromRightBranch = next(deletedContact);//находим самый левый элемент в правой ветке
		//у найденного эелемента точно нету потомков слева, но могут быть потомки справа

		if (minFromRightBranch){
			//если элемент найден переписываем значения из него в удаляемый
			deletedContact->name = minFromRightBranch->name;
			deletedContact->number = minFromRightBranch->number;

			if (minFromRightBranch->right == NULL){//если потомков справа у нашего "левого" нету, т.е он лист, т.к (слева точно ничего нету)

				if (minFromRightBranch == minFromRightBranch->parent->right){
					minFromRightBranch->parent->right = NULL;
				}
				else {
					minFromRightBranch->parent->left = NULL; //переписываем правый указатель у родителя на пустой, левый не трогаем;
				}

				delete minFromRightBranch;//удаляем лист
			}
			else {
				//если у "левого" есть правая ветка, переписываем левый указатель у родителя на эту правую ветку
				if (minFromRightBranch == minFromRightBranch->parent->right){
					minFromRightBranch->parent->right = minFromRightBranch->right;
					minFromRightBranch->right->parent = minFromRightBranch->parent;
				}
				else {
					minFromRightBranch->parent->left = minFromRightBranch->right;
					minFromRightBranch->right->parent = minFromRightBranch->parent;
				}
				delete minFromRightBranch;
			}

		}
	}
	//случай если справа ветки нету, но есть ветка слева
	else{
		if (deletedContact != NULL && deletedContact->left != NULL){
			maxFromLeftBranch = prev(deletedContact);//находим самый "правый" узел в левой от удаляемого ветке

			if (maxFromLeftBranch){
				//если элемент найден переписываем значения из него в удаляемый
				deletedContact->name = maxFromLeftBranch->name;
				deletedContact->number = maxFromLeftBranch->number;

				if (maxFromLeftBranch->left == NULL){//если потомков слева у нашего "правого" нету, т.е он лист, т.к справа ничего нету			

					if (maxFromLeftBranch == maxFromLeftBranch->parent->left){
						maxFromLeftBranch->parent->left = NULL;
					}
					else {
						maxFromLeftBranch->parent->right = NULL; //переписываем правый указатель у родителя на пустой, левый не трогаем;
					}

					delete maxFromLeftBranch;//удаляем лист
				}
				else {
					//Если у "правого" есть левая ветка,
					if (maxFromLeftBranch == maxFromLeftBranch->parent->left){
						maxFromLeftBranch->parent->left = maxFromLeftBranch->left;
						maxFromLeftBranch->left->parent = maxFromLeftBranch->parent;
					}
					else {
						maxFromLeftBranch->parent->right = maxFromLeftBranch->left;
						maxFromLeftBranch->left->parent = maxFromLeftBranch->parent;
					}
					delete maxFromLeftBranch;
				}
			}
		}
	}
	if (deletedContact == NULL){
		//если мы ошиблись и передали пустую ноду для удаления
		cout << "delete error" << endl;
	}

}

void ContactTree::print(Subscriber* node){
	if (node->parent){
		cout << "parent " << node->parent->name << endl;
	}
	cout << "name " << node->name << endl;
	cout << "number " << node->number << endl << endl;
}

ContactTree::Subscriber* getRoot(ContactTree* A){
	return A->root;
}
