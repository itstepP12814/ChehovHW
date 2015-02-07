#include <iostream>
#include <map>
#include <string>
using namespace std;

class Fraction{
public:
	Fraction(){}
	Fraction(int x, int y) :num(x), denom(y){}
	Fraction(int x) : num(x), denom(1){}
	Fraction(const Fraction& f) : num(f.num), denom(f.denom){}
	~Fraction(){}
	operator double() const {
		return ((double)num) / denom;
	}
	operator int() const {
		return num / denom;
	}
	void print(){
		cout << num << "/" << denom << endl;
	}
	int num;
	int denom;
};
int main(){
	Fraction A(1, 3);
	cout << (double)A;
	double a = (double)A;
	map < Fraction, string > arr;
	arr[Fraction(1, 2)] = "one second";
	arr[Fraction(1, 3)] = "one third";
	arr[Fraction(1, 4)] = "one fourth";
	arr[Fraction(1, 5)] = "one fifth";
	for (map <Fraction, string >::iterator itt = arr.begin(); itt != arr.end(); ++itt){
		if ((double)(itt->first) == a) {
			cout << itt->second;
		}
	}
	return 0;
}