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
void Gai_tree::showTree(Car* node){
	if (node != NULL){
		showTree(node->leftCar);
		print(node);
		showTree(node->rightCar);
	}
}
Gai_tree::Car* Gai_tree::search(const string& index, Car* node){
	//тут и далее в качестве первоначальной ноды всегда передается рутовя нода
	if (node != NULL){
		search(index, node->leftCar);
		if (index == node->number){
			cout << "car is find!" << endl;
			print(node);
			return node;
		}
		search(index, node->rightCar);
	}
}
void Gai_tree::searchDiapasone(const string& index1, const string& index2, Car* node){
	//преобразование строк к числам
	const char* temp_index1 = index1.c_str();//первый номер диапазона
	const char* temp_index2 = index2.c_str();//второй номер диапазона
	int ind1 = atoi(temp_index1);
	int ind2 = atoi(temp_index2);


	if (node != NULL){
		/*Мы идем по дереву и спускаемся все время вниз(или вверх) влево, и в итоге мы натыкаемся на пустую ноду,
		после которой условие первого if не выполняется и мы "поднимаемся" на одну ноду вверх, возвращаясь назад в предыдущую запущенную функцию.
		Запускается проверка второго if на соответствие условиям поиска в диапазоне. Из-за того что проходя по дереву мы натыкаемся
		на пустую NULL ноду, нужно обязательно делать получение номера машины (temp_node=node->number.c_str();) и преобразование к числу,
		строго ПОСЛЕ проверки на то пустая нода или нет, если вынести преобразование номера текущей ноды до проверки первого if(например после temp_index1 и temp_index2),
		то мы столкнемся с ошибкой сегментирования т.к попытаемся прочитать данные из области памяти с NULL*/

		const char* temp_node = node->number.c_str();//номер текущей ноды(узла или машины)
		int index_node = atoi(temp_node);
		searchDiapasone(index1, index2, node->leftCar);
		if (index_node >= ind1 && index_node <= ind2){
			print(node);
		}
		searchDiapasone(index1, index2, node->rightCar);
	}
}

Gai_tree::Car* getRoot(const Gai_tree A){
	return A.root;
}
void print(Gai_tree::Car* node){
	cout << "number " << node->number << endl;
	cout << "speeding " << node->ticket.speeding << endl;
	cout << "illegal parkind " << node->ticket.illegal_parking << endl;
	cout << "running on red " << node->ticket.running_on_red << endl << endl;
}