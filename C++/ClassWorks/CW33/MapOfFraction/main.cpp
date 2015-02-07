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
	bool operator< (const Fraction& F) const {
		if (((double)num / denom) < ((double)F.num / F.denom)){
			return true;
		}
		else return false;
	}
	void print(){
		cout << num << "/" << denom << endl;
	}
	int num;
	int denom;
};
int main(){
	Fraction A(300, 150);
	double a = A;
	map < Fraction, string > arr;
	arr[Fraction(1)] = "one";
	arr[Fraction(1, 2)] = "one-second";
	arr[Fraction(1, 3)] = "one-third";
	arr[Fraction(1, 4)] = "one-fourth";
	arr[Fraction(1, 5)] = "one-fifth";
	arr[Fraction(1, 6)] = "one-sixth";
	arr[Fraction(1, 7)] = "one-seventh";
	arr[Fraction(1, 8)] = "one-eighth";
	arr[Fraction(1, 9)] = "one-ninth";
	arr[Fraction(1, 10)] = "one-tenth";
	map <Fraction, string>::iterator i;
	for (map <Fraction, string >::iterator itt = arr.begin(); itt != arr.end(); ++itt){
		if ((double)(itt->first) < a) {
			//cout << itt->second << endl;
			i = itt;
		}
		else {
			//cout << itt->second << endl;
			i = itt;
			break;
		}
	}
	cout << i->second << endl;
	return 0;
}