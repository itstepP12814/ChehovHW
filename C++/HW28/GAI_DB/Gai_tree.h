#pragma once
#include <iostream>
#include <string>
using namespace std;

class Gai_tree
{
public:
	Gai_tree();
	virtual ~Gai_tree();
	//структура билета со штрафом
	struct Offence {
		int speeding;
		int illegal_parking;
		int running_on_red;
	};
	//машина 
	class Car{
	public:
		string number;
		Offence ticket;
		Car* leftCar;
		Car* rightCar;
		Car(const string& index) : leftCar(NULL), rightCar(NULL), number(index), ticket({ 0, 0, 0 }) {}
		virtual ~Car(){
			delete leftCar;
			delete rightCar;
		}
	};
	size_t size_of_tree; //кол-во узлов
	Offence& operator[](const string& index);
	void showTree(Car*);
	Car* search(const string&, Car*);
	void searchDiapasone(const string&, const string&, Car*);
	/*дружественные функции для печати и получения рутового узла, можно было сделать и как методы
	но я хотел попрактиковаться с использованием областей видимости*/
	friend Car* getRoot(Gai_tree A);
	friend void print(Car*);
private:
	Car* root;//самая первая нода
};

