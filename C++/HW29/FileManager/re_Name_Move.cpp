#include "FileManager.h"

void renameFile(const string source,const string newName){
	_finddata_t *fileinfo = new _finddata_t;
	const char* lstSlash = strrchr(source.c_str(), '\\');
	string a = lstSlash;
	cout << a;
}