#include <iostream>
#include <string>

using namespace std;

class Quadro{
public:
	Quadro() :x(0), y(0){}
	Quadro(int _x) : x(_x), y(_x){}
	virtual ~Quadro(){}

protected:
	int x;//длина
	int y;//ширина, собстно они равны
};
class Circle{
public:
	Circle() :radius(0), diametr(radius){}
	Circle(int r) : radius(r), diametr(2 * radius){}
	virtual ~Circle(){}
protected:
	int radius;
	int diametr;
};

class CircleInQuadro : public Quadro, public Circle{
public:
	CircleInQuadro(){}
	CircleInQuadro(int r, int side){
		radius = r;
		diametr = 2 * r;
		x = y = side;
	}
	virtual~CircleInQuadro(){}
	void check(){
		if ((radius == (x / 2)) && (0==(x % 2))){
			cout << "correct!\n";
		}
		else{
			cout << "error!\n";
		}
	}
};

int main(){
	CircleInQuadro A(5, 10);
	A.check();
	return 0;
}