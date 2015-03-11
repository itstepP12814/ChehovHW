#include "FileManager.h"

int main(){
	try{
		//moveAllFiles("D:\\GitHub\\test\\", "D:\\GitHub\\copy_test\\");
		//copyAllFiles("D:\\src\\", "D:\\dst\\");
		//showAllFiles("D:\\GitHub\\test\\");
		copyFile("D:\\src\\test.mp3", "D:\\dst\\");
	    //moveFile("D:\\GitHub\\test\\folder2", "D:\\GitHub\\copy_test\\");
		//renameFile("D:\\GitHub\\test\\folder2", "file1-2.txt");
		//removeAllFiles("D:\\GitHub\\test\\src\\");
	}
	catch (exception ex){
		cout << ex.what();
	}
	return 0;
}