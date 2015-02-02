#include "FileManager.h"

int main(){

	try{
		moveAllFiles("D:\\GitHub\\test\\", "D:\\GitHub\\copy_test\\");
		//copyAllFiles("D:\\GitHub\\test\\", "D:\\GitHub\\copy_test\\");
	}
	catch (exception ex){
		cout << ex.what();
	}
	return 0;
}