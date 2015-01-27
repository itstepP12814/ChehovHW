#include "Gai_tree.h"

Gai_tree::Gai_tree() : size_of_tree(0), root(NULL)
{
}


Gai_tree::~Gai_tree()
{
}

Gai_tree::Offence& Gai_tree::operator[](const string& index){
	Car** current = &root;
	while ((*current) != NULL){
		if (index == (*current)->number){
			return (*current)->ticket;
		}
		if (index < (*current)->number){
			current = &((*current)->leftCar);
		}
		else {
			current = &((*current)->rightCar);
		}
	}
	(*current) = new Car(index);
	++size_of_tree;
	return (*current)->ticket;
}
void Gai_tree::showTree(Car* current_car){
	/*Мы идем по дереву и спускаемся все время вниз(или вверх) влево, и в итоге мы натыкаемся на пустую ноду,
	после которой условие if не выполняется и мы "поднимаемся" на одну ноду вверх, возвращаясь назад в предыдущую запущенную функцию.
	Из-за того что проходя по дереву мы натыкаемсяна пустую NULL ноду, нужно обязательно делать печать данных машины строго ПОСЛЕ проверки условия
	пустая нода или нет, иначе мы столкнемся с ошибкой сегментирования т.к попытаемся прочитать данные из области памяти с NULL*/
	if (current_car != NULL){
		showTree(current_car->leftCar);
		print(current_car);
		showTree(current_car->rightCar);
	}
}
Gai_tree::Car* Gai_tree::search(const string& index, Car* current_car){
	//тут и далее в качестве первоначальной ноды всегда передается рутовя нода
	if (current_car != NULL){
		search(index, current_car->leftCar);
		if (index == current_car->number){
			cout << "car is find!" << endl;
			print(current_car);
			return current_car;
		}
		search(index, current_car->rightCar);
	}
}
void Gai_tree::searchDiapasone(const string& index1, const string& index2, Car* current_car){
	if (current_car != NULL){
		searchDiapasone(index1, index2, current_car->leftCar);
		if (index1 <= current_car->number && current_car->number <= index2){
			print(current_car);
		}
		searchDiapasone(index1, index2, current_car->rightCar);
	}
}

Gai_tree::Car* getRoot(const Gai_tree A){
	return A.root;
}
void print(Gai_tree::Car* current_car){
	cout << "number " << current_car->number << endl;
	cout << "speeding " << current_car->ticket.speeding << endl;
	cout << "illegal parkind " << current_car->ticket.illegal_parking << endl;
	cout << "running on red " << current_car->ticket.running_on_red << endl << endl;
}