#include "Reader.h"
using namespace std;
int main(){
	Reader A("list.csv");
	try {
		A.read();
	}
	catch (exception ex) {
		cout << ex.what();
	}
	return 0;
}