#include "FileManager.h"


string parser(string source){
	//строго говоря тут нифига не парсер, а достовляльщик звездочек
	if (strstr(source.c_str(), "*.*")){//случай если маска явно задана
		return source;
	}
	if (strstr(source.c_str(), ".")){//если просто файл с любым расширением
		return source;
	}
	return source += "*.*";
}
int answer(const _finddata_t* fileinfo){
	if (fileinfo->attrib &_A_SUBDIR){
		cout << "replace the current subdirectory?" << endl;
	}
	else {
		cout << "replace the current file?" << endl;
	}
	cout << fileinfo->name << endl << "Y/N" << endl;
	char answer;
	cin >> answer;
	switch (answer){
	case 'Y': return 1;
		break;
	case 'y': return 1;
		break;
	case 'N': return 0;
		break;
	case 'n': return 0;
		break;
	default: return 1;
	}
}