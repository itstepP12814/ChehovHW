#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
//9. Игрок делает ходы в плоском мире, разбитом на клетки.
//На каждом ходу игрок помечает клетку на которой он находится, затем может с равной вероятностью повернуться на + -90 градусов 
//либо оставить прежнее направление.После этого он делает шаг вперёд на одну клетку, и помечает эту клетку.
//Сколько ходов сделает игрок пока не дойдёт до ранее помеченной клетки ?

class Player;
class Cell{
public:
	Cell() :hereNow(false), wasHere(false) {};
	~Cell(){};
	void show(){
		cout << hereNow;
		cout << wasHere;
	}
	friend Player;
private:
	bool hereNow;
	bool wasHere;
};

class Player{
public:
	Player(){};
	~Player(){};
	void mark(Cell& currentCell){//метод делает метку
		currentCell.hereNow = true;
		currentCell.wasHere = true;
	}
	void swithcher(int t){
		switch (t)
		{
		case 1: goRigth();
			break;
		case 2: goLeft();
			break;
		case 3: goForward();
			break;
		default:
			break;
		}
	}
	void goRigth(){
		
	}
	void goLeft(){}
	void goForward(){}
};

int main(){
	srand(time(NULL));
	Cell copy;
	Player P;
	vector<vector<Cell>> field(50, vector<Cell>(50, copy));



	//for (vector<vector<Cell>>::iterator it = field.begin(); it != field.end(); ++it){
	//	for (vector<Cell>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2){
	//		//out
	//	}
	//}


	return 0;
}