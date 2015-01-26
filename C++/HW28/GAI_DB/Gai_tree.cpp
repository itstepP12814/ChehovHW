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
			current = &((*current)->leftCar->ticket);
		}
		else {
			current = &((*current)->rightCar->ticket);
		}
	}
	(*current) = new Car(index);
	++size_of_tree;
	return (*current)->ticket;
}
void Gai_tree::showTree(Car* node){
	showTree(node->leftCar);
	cout << "speeding" << node->ticket.speeding << endl;
	cout << "illegal parkind" << node->ticket.illegal_parking << endl;
	cout << "running on red" << node->ticket.running_on_red << endl;
	showTree(node->rightCar);
}