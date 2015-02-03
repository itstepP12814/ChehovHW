#include "FileManager.h"
void showAllFiles(string source){
	string mask = parser(source);
	_finddata_t *fileinfo = new _finddata_t;
	int done = _findfirst(mask.c_str(), fileinfo);
	done = _findfirst(mask.c_str(), fileinfo);
	if (done == -1){
		throw exception("source directory is not found!\n");
	}
	int checker=1, countFile = 0, countDir = 0;
	//за имена файлов каталогов на которые я натыкаюсь .\ и ..\ ???
	//если дважды сделать findnext - все ок, видимо потому что мы переходим по этим двум файлам.
	while (checker != -1){
		if (fileinfo->attrib &_A_SUBDIR && checker!=-1){//правило для отображения поддиректорий
			++countDir;
			cout << fileinfo->name << "\\\n";
		}
		else {
			++countFile;
			cout << fileinfo->name << endl;
		}
		checker = _findnext(done, fileinfo);
	}
	cout << "totally: " << countFile << " files" << endl;
	cout << "\t " << countDir << " folders" << endl;
}