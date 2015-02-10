#include <iostream>
#include <string>
#include <exception>
using namespace std;

int main(){
	int d;
	long long _d;
	string a = "5085246850852468";
	try{
		d = atoi(a.c_str());
		_d = atoll(a.c_str());
		if (d != _d){
			throw exception("int error\n");
		}
		cout << d << endl;
	}
	catch (exception ex){
		cout << ex.what() << endl;
	}
	return 0;
}