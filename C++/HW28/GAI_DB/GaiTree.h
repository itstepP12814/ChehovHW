#pragma once
#include <iostream>
#include <string>
using namespace std;

class GaiTree
{
public:
	GaiTree();
	virtual ~GaiTree();
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
		Car* prev_car;
		Car* left_car;
		Car* right_car;
		Car(const string& index) : left_car(NULL), right_car(NULL), prev_car(NULL), number(index), ticket({ 0, 0, 0 }) {}
		virtual ~Car(){
			delete left_car;
			delete right_car;
			delete prev_car;
		}
	};
	size_t size_of_tree; //кол-во узлов
	Offence& operator[](const string& index);
	void showTree(Car*);
	Car* search(const string&);
	void searchDiapasone(const string&, const string&, Car*);
	/*дружественные функции для печати и получения рутового узла, можно было сделать и как методы
	но я хотел попрактиковаться с использованием областей видимости*/
	friend Car* getRoot(GaiTree);
	friend void print(Car*);
private:
	Car* root;//самая первая нода
};

