#include "GaiTree.h"

GaiTree::GaiTree() : size_of_tree(0), root(NULL)
{
}


GaiTree::~GaiTree()
{
}

GaiTree::Offence& GaiTree::operator[](const string& index){
	Car** current_car = &root;

	while ((*current_car) != NULL){
		if (index == (*current_car)->number){
			return (*current_car)->ticket;
		}
		if (index < (*current_car)->number){
			current_car = &((*current_car)->left_car);
		}
		else {
			current_car = &((*current_car)->right_car);
		}
	}
	(*current_car) = new Car(index);
	++size_of_tree;
	return (*current_car)->ticket;
}
void GaiTree::showTree(Car* current_car){
	/*Мы идем по дереву и спускаемся все время вниз(или вверх) влево, и в итоге мы натыкаемся на пустую ноду,
	после которой условие if не выполняется и мы "поднимаемся" на одну ноду вверх, возвращаясь назад в предыдущую запущенную функцию.
	Из-за того что проходя по дереву мы натыкаемсяна пустую NULL ноду, нужно обязательно делать печать данных машины строго ПОСЛЕ проверки условия
	пустая нода или нет, иначе мы столкнемся с ошибкой сегментирования т.к попытаемся прочитать данные из области памяти с NULL*/
	if (current_car != NULL){
		showTree(current_car->left_car);
		print(current_car);
		showTree(current_car->right_car);
	}
}
GaiTree::Car* GaiTree::search(const string& index){
	//тут и далее в качестве первоначальной ноды всегда передается рутовя нода
	Car** current_car = &root;
	while ((*current_car) != NULL){
		if (index == (*current_car)->number){
			cout << "car is find!" << endl;
			print((*current_car));
			return (*current_car);
		}
		if (index < (*current_car)->number) {
			current_car = &((*current_car)->left_car);
		}
		else {
			current_car = &((*current_car)->right_car);
		}
	}
}
void GaiTree::searchDiapasone(const string& index1, const string& index2, Car* current_car){
	if (current_car != NULL){
		searchDiapasone(index1, index2, current_car->left_car);
		if (index1 <= current_car->number && current_car->number <= index2){
			print(current_car);
		}
		searchDiapasone(index1, index2, current_car->right_car);
	}
}

GaiTree::Car* getRoot(const GaiTree A){
	return A.root;
}
void print(GaiTree::Car* current_car){
	cout << "number " << current_car->number << endl;
	cout << "speeding " << current_car->ticket.speeding << endl;
	cout << "illegal parkind " << current_car->ticket.illegal_parking << endl;
	cout << "running on red " << current_car->ticket.running_on_red << endl << endl;
}