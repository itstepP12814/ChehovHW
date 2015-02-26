#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
//9. »грок делает ходы в плоском мире, разбитом на клетки.
//Ќа каждом ходу игрок помечает клетку на которой он находитс€, затем может с равной веро€тностью повернутьс€ на + -90 градусов 
//либо оставить прежнее направление.ѕосле этого он делает шаг вперЄд на одну клетку, и помечает эту клетку.
//—колько ходов сделает игрок пока не дойдЄт до ранее помеченной клетки ?

class Player;
class Cell{
public:
	Cell() :wasHere(false) {};
	~Cell(){};
	void show(){
		if (wasHere == true) cout << "*";
		else cout << ".";
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

	void out() {
		for (vector<vector<Cell>>::iterator it = field.begin(); it != field.end(); ++it){
			for (vector<Cell>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2){
				(*it2).show();
			}
			cout << endl;
		}
		cout << endl;
	}

	friend Player;
	pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator> beg;
private:
	vector<vector<Cell>> field;

};

class Player{
public:
	Player(pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator> pos, Field &F) : currentPosition(pos), prevPosition(pos), field(F){};
	~Player(){};
	void mark(){
		static int count = 0;
		if ((*currentPosition.second).wasHere == false){
			(*currentPosition.second).wasHere = true;
		}
		else {
			cout << "Player was here "<< count << endl;
			system("pause");
		}
		++count;
	}

	void switcher(int t){
		switch (t)
		{
		case 1: goRight();
			mark();
			break;
		case 2: goLeft();
			mark();
			break;
		case 3: goForward();
			mark();
			break;
		default:
			break;
		}
	}

	void goRight(){
		//ptrdiff_t dist_row = distance(vector<vector<Cell>>::iterator(field.field.begin()), vector<vector<Cell>>::iterator(currentPosition.first));
		ptrdiff_t dist_col = distance(vector<Cell>::iterator((*currentPosition.first).begin()), vector<Cell>::iterator(currentPosition.second));//был prevPosition.second

		if (currentPosition.first != prevPosition.first){//определ€ем пришли ли мы вообще с верху/снизу или сбоку

			if (currentPosition.first > prevPosition.first){//смотрим пришли мы снизу или сверху
				if (currentPosition.second != (*currentPosition.first).begin()){
					prevPosition = currentPosition;
					currentPosition.second = --currentPosition.second;
				}
			}
			else {
				if (currentPosition.second != (*currentPosition.first).end()){//пришли сверху
					prevPosition = currentPosition;
					currentPosition.second = ++currentPosition.second;
				}
			}

		}
		else {//мы пришли сбоку
			if (currentPosition.second > prevPosition.second){//пришли справа
				if (currentPosition.first != field.field.end()){
					prevPosition = currentPosition;
					currentPosition.first = ++currentPosition.first;
					currentPosition.second = (*currentPosition.first).begin() + dist_col;
				}
			}
			else {//слева
				if (currentPosition.first != field.field.begin()){
					prevPosition = currentPosition;
					currentPosition.first = --currentPosition.first;
					currentPosition.second = (*currentPosition.first).begin() + dist_col;
				}
			}

		}
	}

	void goLeft(){
		ptrdiff_t dist_col = distance(vector<Cell>::iterator((*currentPosition.first).begin()), vector<Cell>::iterator(currentPosition.second));

		if (currentPosition.first != prevPosition.first){//определ€ем пришли ли мы вообще с верху/снизу или сбоку

			if (currentPosition.first > prevPosition.first){//смотрим пришли мы снизу или сверху
				if (currentPosition.second != (*currentPosition.first).end()){
					prevPosition = currentPosition;
					currentPosition.second = ++currentPosition.second;
				}
			}
			else {
				if (currentPosition.second != (*currentPosition.first).begin()){//пришли сверху
					prevPosition = currentPosition;
					currentPosition.second = --currentPosition.second;
				}
			}

		}
		else {//мы пришли сбоку
			if (currentPosition.second > prevPosition.second){//пришли слева
				if (currentPosition.first != field.field.begin()){
					prevPosition = currentPosition;
					currentPosition.first = --currentPosition.first;
					currentPosition.second = (*currentPosition.first).begin() + dist_col;
				}
			}
			else {//справа
				if (currentPosition.first != field.field.end()){
					prevPosition = currentPosition;
					currentPosition.first = ++currentPosition.first;
					currentPosition.second = (*currentPosition.first).begin() + dist_col;
				}
			}

		}
	}
	void goForward(){
		ptrdiff_t dist_col = distance(vector<Cell>::iterator((*currentPosition.first).begin()), vector<Cell>::iterator(currentPosition.second));

		if (currentPosition.first != prevPosition.first){
			if (currentPosition.first > prevPosition.first){
				if (currentPosition.first != field.field.end()){
					prevPosition = currentPosition;
					currentPosition.first = ++currentPosition.first;
					currentPosition.second = (*currentPosition.first).begin() + dist_col;
				}
			}
			else {
				if (currentPosition.first != field.field.begin()){
					prevPosition = currentPosition;
					currentPosition.first = --currentPosition.first;
					currentPosition.second = (*currentPosition.first).begin() + dist_col;
				}
			}
		}
		else {
			if (currentPosition.second > prevPosition.second){
				if (currentPosition.second != (*currentPosition.first).end()){
					prevPosition = currentPosition;
					currentPosition.second = ++currentPosition.second;
				}
			}
			else {
				if (currentPosition.second != (*currentPosition.first).begin()){
					prevPosition = currentPosition;
					currentPosition.second = --currentPosition.second;
				}
			}
		}
	}

private:
	pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator> prevPosition;
	pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator> currentPosition;
	Field &field;
};

int main(){
	srand(time(NULL));
	Cell copy;

	Field F(pair<int, int>(20, 50), copy);//создание пол€ 5*5
	Player P(pair<vector<vector<Cell>>::iterator, vector<Cell>::iterator>(F.beg), F);//создание и инициализаци€ позиции игрока 0*0
	for (int i = 0; i < 100; ++i){
		P.switcher(rand() % 3 + 1);
		F.out();
		int s = time(0);
		while (s == time(0));
		system("cls");
	}

	return 0;
}