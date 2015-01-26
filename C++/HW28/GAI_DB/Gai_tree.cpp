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