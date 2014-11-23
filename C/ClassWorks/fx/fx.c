
#include <iostream>
#include <cstdlib>
#include <fstream>//для работы с выводом в файл
#include <ctime>
using namespace std;

int sample() {
	srand(time(NULL));
		ofstream out("fx.csv");
		for(int i=0; i<100; i++) {
		out<<(rand()%10)<<";"<<(rand()%25-12)<<endl;
    }
    	return 0;
} 

