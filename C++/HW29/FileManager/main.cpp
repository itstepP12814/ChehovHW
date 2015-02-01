#include "FileManager.h"

int main(){
	FileManager A;

	try{
		//A.copyAllFiles("D:\\GitHub\\test\\", "D:\\GitHub\\copy_test\\");
		A.moveAllFiles("D:\\GitHub\\test\\", "D:\\GitHub\\copy_test\\");
	}
	catch (exception ex){
		cout << ex.what();
	}
	return 0;
}