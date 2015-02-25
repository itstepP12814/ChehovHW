#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
//9. Игрок делает ходы в плоском мире, разбитом на клетки.
//На каждом ходу игрок помечает клетку на которой он находится, затем может с равной вероятностью повернуться на + -90 градусов 
//либо оставить прежнее направление.После этого он делает шаг вперёд на одну клетку, и помечает эту клетку.
//Сколько ходов сделает игрок пока не дойдёт до ранее помеченной клетки ?

class Player;
class Cell{
public:
	Cell() :wasHere(false) {};
	~Cell(){};
	void show(){
		cout << wasHere;
	}
	friend Player;
private:
	bool wasHere;
};
class Field{
public:
	Field(){};
	Field(pair<int, int> size, Cell copy) {
		vector<vector<Cell>> f(size.first, vector<Cell>(size.second, copy));
		field = f;
		beg.first = field.begin();
		beg.second = (*field.begin()).begin();
	};
	~Field(){};
	friend Player;
	vector<vector<Cell>> field;
	pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator> beg;

};

class Player{
public:
	Player(){};
	Player(pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator> pos) : currentPosition(pos), prevPosition(pos){};
	~Player(){};
	void mark(pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator> pos, Field &field){
		if ((*currentPosition.second).wasHere == false){
			(*currentPosition.second).wasHere = true;
		}
	}

	void switcher(int t, Field &field){
		switch (t)
		{
		case 1: goRigth(field);
			mark(currentPosition, field);
			break;
		case 2: goLeft(field);
			mark(currentPosition, field);
			break;
		case 3: goForward(field);
			mark(currentPosition, field);
			break;
		default:
			break;
		}
	}
	void goRigth(Field &field){
		ptrdiff_t dist_row = distance(vector<vector<Cell>>::iterator(field.field.begin()), vector<vector<Cell>>::iterator(currentPosition.first));
		ptrdiff_t dist_col;
		if (currentPosition.first == prevPosition.first){
			dist_col = distance(vector<Cell>::iterator((*currentPosition.first).begin()), vector<Cell>::iterator(prevPosition.second));
		}
		else {
			currentPosition.second = (*currentPosition.first).begin();
			dist_col = distance(vector<Cell>::iterator((*currentPosition.first).begin()), vector<Cell>::iterator(currentPosition.second));

		}

		if (currentPosition.first != prevPosition.first){//если мы пришли с другого ряда, то поворачиваем соотвественно в пределах текущего ряда
			if (currentPosition.first > prevPosition.first){//если номер предыдущего ряда меньше, значит мы шли снизу вверх, вправо сдвинемься на одну колонку
				prevPosition = currentPosition;//делаем текущую позицию предыдущей, после чего высчитываем новую текущую позицию
				currentPosition.second = (*currentPosition.first).begin() + dist_col;
				if (currentPosition.second != (*currentPosition.first).end()){//проверяем не уперлись ли мы в конец ряда
					currentPosition.second = ++currentPosition.second;//идем право
				}
			}
			else {//иначе - шли серху вниз, сдвинемься на одну колонку
				prevPosition = currentPosition;
				currentPosition.second = (*currentPosition.first).begin() + dist_col;
				if (currentPosition.second != (*field.field.begin()).begin())
					currentPosition.second = --currentPosition.second;//идем лево
			}
		}
		else {//значит мы пришли с того же ряда но из другой колонки, знаит будем перемещаться на ряд вверх или вниз
			if (currentPosition.second > prevPosition.second){
				prevPosition = currentPosition;
				if (currentPosition.first != field.field.begin())
					currentPosition.first = --currentPosition.first;//идем вниз
			}
			else{
				prevPosition = currentPosition;
				if (currentPosition.first != field.field.end()){
					currentPosition.first = ++currentPosition.first;//идем вверх
				}
			}
		}
	}
	void goLeft(Field &field){
		ptrdiff_t dist_row = distance(vector<vector<Cell>>::iterator(field.field.begin()), vector<vector<Cell>>::iterator(currentPosition.first));//между рядами
		ptrdiff_t dist_col; //разница между колонками
		if (currentPosition.first == prevPosition.first){
			dist_col = distance(vector<Cell>::iterator((*currentPosition.first).begin()), vector<Cell>::iterator(prevPosition.second));
		}
		else {
			currentPosition.second = (*currentPosition.first).begin();
			dist_col = distance(vector<Cell>::iterator((*currentPosition.first).begin()), vector<Cell>::iterator(currentPosition.second));

		}
		if (currentPosition.first != prevPosition.first){
			if (currentPosition.first > prevPosition.first){
				prevPosition = currentPosition;
				currentPosition.second = (*currentPosition.first).begin()+dist_col;//сдвигаем указатель текущего вектора на величину, на которую был сдвинут такой же итератор у предыдущего вектора
				if (currentPosition.second != (*currentPosition.first).end()){
					currentPosition.second = ++currentPosition.second;
				}
			}
			else {
				prevPosition = currentPosition;
				currentPosition.second = (*currentPosition.first).begin() + dist_col;
				if (currentPosition.second != (*currentPosition.first).begin())
					currentPosition.second = --currentPosition.second;
			}
		}
		else {
			if (currentPosition.second > prevPosition.second){
				prevPosition = currentPosition;
				if (currentPosition.first != field.field.end())
					currentPosition.first = ++currentPosition.first;
			}
			else {
				prevPosition = currentPosition;
				if (currentPosition.first != field.field.begin())
					currentPosition.first = --currentPosition.first;
			}
		}
	}
	void goForward(Field &field){
		ptrdiff_t dist_row = distance(vector<vector<Cell>>::iterator(field.field.begin()), vector<vector<Cell>>::iterator(currentPosition.first));
		ptrdiff_t dist_col;
		if (currentPosition.first == prevPosition.first){
			dist_col = distance(vector<Cell>::iterator((*currentPosition.first).begin()), vector<Cell>::iterator(prevPosition.second));
		}
		else {
			currentPosition.second = (*currentPosition.first).begin();
			dist_col = distance(vector<Cell>::iterator((*currentPosition.first).begin()), vector<Cell>::iterator(currentPosition.second));
		}

		if (currentPosition.first != prevPosition.first){//если индексы рядов не равны значит мы движемсья прямо между рядами
			if (currentPosition.first > prevPosition.first){//определяем куда именно вниз/вверх
				prevPosition = currentPosition;
				if (currentPosition.first != field.field.end())
					currentPosition.first = ++currentPosition.first;
			}
			else {
				prevPosition = currentPosition;
				if (currentPosition.first != field.field.begin())
					currentPosition.first = --currentPosition.first;
			}

		}
		else {//значит движемься между колонками в переделах одного ряда
			if (currentPosition.second > prevPosition.second){//движемься слева направо
				prevPosition = currentPosition;
				if (currentPosition.second != (*field.field.begin()).begin())
					currentPosition.second = --currentPosition.second;
			}
			else {
				prevPosition = currentPosition;
				if (currentPosition.second != (*field.field.begin()).end())
					currentPosition.second = ++currentPosition.second;
			}
		}
	}
private:
	pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator> prevPosition;
	pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator> currentPosition;
};

int main(){
	srand(time(NULL));
	Cell copy;

	Field F(pair<int, int>(5, 5), copy);//создание поля 5*5
	Player P(pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator>(F.beg));//создание и инициализация позиции игрока 0*0
	P.switcher(2, F);
	P.switcher(1, F);
	P.switcher(1, F);
	P.switcher(2, F);
	P.switcher(1, F);
	P.switcher(1, F);



	////out
	for (vector<vector<Cell>>::iterator it = F.field.begin(); it != F.field.end(); ++it){
		for (vector<Cell>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2){
			(*it2).show();
		}
		cout << endl;
	}
	return 0;
}