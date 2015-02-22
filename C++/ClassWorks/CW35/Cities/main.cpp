#include <iostream>
#include <map>
#include <math.h>
#include <string>
using namespace std;

class Point{
public:
	Point() : x(0), y(0){};
	Point(int _x, int _y) : x(_x), y(_y){};
	virtual ~Point(){};

	bool operator<(const Point& T) const {
		const Point Target(1, 5);
		int distanceThis = pow(Target.x - x, 2) + pow(Target.y - y, 2);
		int distanceT = pow(Target.x - T.x, 2) + pow(Target.y - T.y, 2);
		if (distanceThis < distanceT) return true;
		else return false;
	}
	int x, y;
};


int main(){
	map<Point, string> cities;
	cities[Point(22,17)]="Minsk";
	cities[Point(34, 18)] = "Borisov";
	cities[Point(34, 22)] = "Gomel";
	cities[Point(54, 22)] = "Mogilev";
	cities[Point(65, 92)] = "Drogichin";
	for (pair<Point, string> i:cities){
		cout << i.second << endl;
	}
	return 0;
}