#include <iostream>
#include <vector>
using namespace std;

class Fraction{
public:
	Fraction(){}
	Fraction(int x, int y) :num(x), denom(y){}
	Fraction(int x) : num(x), denom(1){}
	Fraction(const Fraction& f) : num(f.num), denom(f.denom){ cout << "copy\n"; }
	~Fraction(){}
	operator double(){
		return ((int)num) / denom;
	}
	operator int() {
		return num / denom;
	}
	void print(){
		cout << num << "/" << denom << endl;
	}
	int num;
	int denom;
};

int main(){
	Fraction a(8, 2);
	a.print();
	vector <Fraction> arr(6, 1);
	vector <Fraction> arrr(6, Fraction(7, 9));
	for (Fraction x : arr){
		//тип данных можно заменить словом auto for(auto x: arr)
		x.print();
	}
	//Fraction b = 8;
	return 0;
}