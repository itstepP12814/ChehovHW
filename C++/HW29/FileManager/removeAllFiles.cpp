#include "FileManager.h"

void removeAllFiles(const string source){
	_finddata_t *fileinfo = new _finddata_t;
	string mask = parser(source);
	int done, checker;
	done = _findfirst(mask.c_str(), fileinfo);
	if (done == -1){
		throw exception("cant open remove directory!\n");
	}
	while ((strcmp(fileinfo->name, ".") == 0) || (strcmp(fileinfo->name, "..") == 0)){
		checker = _findnext(done, fileinfo);
	}
	string src, filename;
	while (checker != -1){
		while (checker != -1 && fileinfo->attrib &_A_SUBDIR){
			src = source + fileinfo->name + "\\";
			removeAllFiles(src);
			if (_rmdir(src.c_str()) == -1){
				throw exception("cant remove directory!\n");
			}
			checker = _findnext(done, fileinfo);
		}
		if (checker != -1){
			filename = source + fileinfo->name;
			if (remove(filename.c_str()) != 0){
				throw exception("cant remove file!\n");
			}
			checker = _findnext(done, fileinfo);
		}
	}
	delete fileinfo;
	_findclose(done);
}