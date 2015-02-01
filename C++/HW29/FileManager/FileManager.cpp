#include "FileManager.h"


FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

void FileManager::moveAllFiles(string source, string destination){
	_finddata_t *fileinfo = new _finddata_t;//Указатель на первый объект структуры с инфой о первом найденном файле
	string mask = source + "*.*";
	int done = _findfirst(mask.c_str(), fileinfo);
	if (done == -1){
		throw exception("source directory is not found!\n");
	}
	//почему нужно сделать findfirst, а потом дважды findnext??? Чтобы наконец перейти к первому файлу в директории, что
	//за имена файлов . и ".."???
	int checker = _findnext(done, fileinfo);
	checker = _findnext(done, fileinfo);

	string oldName = source;
	string newName = destination;

	while (checker != -1){
		while (fileinfo->attrib &_A_SUBDIR && checker != -1){
			string src = source + fileinfo->name + "\\";
			string dst = destination + fileinfo->name + "\\";
			mkdir(dst.c_str());
			moveAllFiles(src, dst);
			rmdir(src.c_str());
			checker = _findnext(done, fileinfo);
		}
		if (checker != -1){
			oldName += fileinfo->name;
			newName += fileinfo->name;
			rename(oldName.c_str(), newName.c_str());
			newName = destination;
			oldName = source;
			checker = _findnext(done, fileinfo);
		}
	}
	_findclose(done);
	delete fileinfo;
}
void FileManager::copyAllFiles(string source, string destination){
	_finddata_t *fileinfo = new _finddata_t;
	string mask = source + "*.*";
	int done = _findfirst(mask.c_str(), fileinfo);
	if (done == -1){
		throw exception("source directory is not found!\n");
	}
	int checker = _findnext(done, fileinfo);
	checker = _findnext(done, fileinfo);

	string oldName = source;
	string newName = destination;
	char buff[_MAX_PATH];
	ifstream fin;
	ofstream fout;
	while (checker != -1){

		while (fileinfo->attrib &_A_SUBDIR && checker != -1){//рекурсивный вызов если нам встретилась поддериктория внутри папки
			string src = source + fileinfo->name + "\\";
			string dst = destination + fileinfo->name + "\\";
			mkdir(dst.c_str());
			copyAllFiles(src, dst);
			checker = _findnext(done, fileinfo);
		}
		/*если поддиректория была последней, то наш чекер измениться и мы не должны пытаться прочитать поддиректорию в потоке ввода*/
		if (checker != -1){
			oldName += fileinfo->name;
			newName += fileinfo->name;

			fin.open(oldName, ios::binary);
			fout.open(newName, ios::binary);
			if (!fin.is_open()){
				throw exception("cant open file!\n");
			}
			//для того чтобы не писать в конец лишний байт
			fin.read(buff, sizeof(char));
			while (!fin.eof()){
				fout.write(buff, sizeof(char));
				fin.read(buff, sizeof(char));
			}
			fin.close();
			fout.close();

			newName = destination;
			oldName = source;
			checker = _findnext(done, fileinfo);
		}
	}
	_findclose(done);
	delete fileinfo;
}