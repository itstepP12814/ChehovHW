#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;
//1. Дано множество различных геометрических фигур, для каждой из которых известен метод вычисления площади.
//Вычислить общую площадь этих фигур.

class Figure{
public:
	string get_name(){
		return name;
	}
	virtual double square() = 0;
protected:
	Figure(){};
	virtual ~Figure(){};
	double sqr;
	string name;
};

class Rectangle : public Figure{
public:
	Rectangle(double len_, double wid_) : len(len_), wid(wid_){
		name = "Rectangle";
	};
	virtual ~Rectangle(){};
	double square(){
		sqr = len*wid;
		return sqr;
	};
private:
	double len;
	double wid;
};

class Triangle : public Figure {
public:
	Triangle(double len_, double wid_) :len(len_), wid(wid_){
		name = "Triangle";
	};
	virtual ~Triangle(){};
	double square(){
		sqr = (len*wid) / 2;
		return sqr;
	};
private:
	int len;
	int wid;
};
class Quadro : public Figure {
public:
	Quadro(double len_) :len(len_){
		name = "Quadro";
	};
	virtual ~Quadro(){};
	double square(){
		sqr = pow(len, 2);
		return sqr;
	}
private:
	double len;
};

class Round : public Figure {
public:
	Round(double rad_) :rad(rad_){
		name = "Round";
	};
	virtual ~Round(){};
	double square(){
		sqr = 3.14 * pow(rad, 2);
		return sqr;
	}
private:
	double rad;
};

int main(){
	double gen_sqr = 0, current_sqr = 0;
	vector<Figure*> figures{ new Triangle(15, 12), new Round(5), new Quadro(7), new Rectangle(16, 4) };
	for (vector<Figure*>::iterator p = figures.begin(); p != figures.end(); ++p){
		cout << (*p)->get_name() <<" ";
		current_sqr = (*p)->square();
		cout << current_sqr << endl;
		gen_sqr += current_sqr;
	}
	cout << "general square " << gen_sqr << endl;
	return 0;
}