#include "Aspirant.h"

Aspirant::Aspirant()
{
}

Aspirant::Aspirant(int ag, char s, string nm, string subj) :scientific_work(subj){
	age = ag;
	name = nm;
	sex = s;
}

Aspirant::~Aspirant()
{
}
void Aspirant::show(){
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "sex: " << sex << endl;
	cout << "sciencific work: " << scientific_work << endl;
}