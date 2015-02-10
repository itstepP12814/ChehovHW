#include <iostream>
#include <time.h>
#include "Stack.h"
using namespace std;

int main(){
	try{
		Stack s;
		int k;
		srand(time(NULL));
		while (!s.isFull()){
			k = rand() % 10 + 1;
			s.pushFront(k);
		}
		s.show();
		printf("\n");
		while (!s.isEmpty()){
			k = s.deleteElement();
			cout << k << endl;
		}
	}
	catch (exception ex){
		cout << ex.what();
	}
	return 0;
}