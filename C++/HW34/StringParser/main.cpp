#include "StringParser.h"
int main(){
	Stack b;
	string out;
	string a = "(35 +(18 +15 )*2 -87 /(19 +25 )* 3 )";
	out = parser(a);
	cout << out << endl;
	return 0;
}