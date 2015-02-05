#include "FileManager.h"
void moveAllFiles(const string source, const string destination){
	_finddata_t *fileinfo = new _finddata_t;//Указатель на первый объект структуры с инфой о первом найденном файле
	_finddata_t *same_fileinfo = new _finddata_t;
	int done, checker = 1, indicatorOfSameFile;
	string src_mask = parser(source);
	done = _findfirst(src_mask.c_str(), fileinfo);
	if (done == -1){
		throw exception("source directory is not found!\n");
	}
	checker = _findnext(done, fileinfo);
	checker = _findnext(done, fileinfo);
	string oldName = source;
	string newName = destination;
	while (checker != -1){
		while (fileinfo->attrib &_A_SUBDIR && checker != -1){
			string src = source + fileinfo->name + "\\";
			string dst = destination + fileinfo->name;
			if (_findfirst(dst.c_str(), same_fileinfo) != -1){ //если нам встретилась поддиректория с таким же названием, как в источнике - спрашиваем че делать
				if (answer(same_fileinfo)){//если говорят заменить добавляем к строке два // чтобы получить путь к папке, и запускаем рекурсию
					dst += "\\";
					mkdir(dst.c_str());
					moveAllFiles(src, dst);
					rmdir(src.c_str());
				}
			}
			else { //если одинаковая поддиректория не встретилась - создаем новую
				dst += "\\";
				mkdir(dst.c_str());
				moveAllFiles(src, dst);
				rmdir(src.c_str());
			}
			checker = _findnext(done, fileinfo);
		}
		if (checker != -1){
			indicatorOfSameFile = 1;
			oldName += fileinfo->name;
			newName += fileinfo->name;
			if (_findfirst(newName.c_str(), same_fileinfo) != -1){ //ищем нет ли такого ж файла в новой директории
				indicatorOfSameFile = answer(same_fileinfo);//спрашиваем че с ним делать
			}
			if (indicatorOfSameFile){//если можно переместить файлы
				if (indicatorOfSameFile != 0 && _findfirst(newName.c_str(), same_fileinfo) != -1){ //если такой же файл присутсвует в директории - удалить
					if (remove(newName.c_str()) != 0){//если файл открыт и удаление не удалось
						throw exception("file is open!\n");
					}
				}
				if (rename(oldName.c_str(), newName.c_str()) != 0){//если по каким-то причинам не удалось переместить/переименовать
					throw exception("cant rename or move file!\n");
				}
				newName = destination;
				oldName = source;
			}
			checker = _findnext(done, fileinfo);
		}
	}
	_findclose(done);
	delete fileinfo;
}
void moveFile(const string source, const string destination){
	_finddata_t *fileinfo = new _finddata_t;
	_finddata_t *same_fileinfo = new _finddata_t;
	int done = 1, indicatorOfSameFile = 1, checkerForFile = 0, checkerForDir = 0;
	done = _findfirst(source.c_str(), fileinfo);
	if (done == -1){
		throw exception("cant find file!\n");
	}
	string dst_mask = parser(destination);
	indicatorOfSameFile = _findfirst(dst_mask.c_str(), same_fileinfo);
	if (indicatorOfSameFile == -1){
		throw exception("cant open destination directory!\n");
	}
	string newName = destination + fileinfo->name;
	indicatorOfSameFile = _findfirst(newName.c_str(), same_fileinfo);
	if (indicatorOfSameFile != -1){
		if (answer(same_fileinfo)){
			checkerForFile = 1;
			checkerForDir = 1;
		}
	}
	else{
		checkerForFile = 1;
		checkerForDir = 1;
	}

	if (fileinfo->attrib &_A_SUBDIR && checkerForDir != 0) {
		mkdir(newName.c_str());
		moveAllFiles(source + "\\", newName + "\\");
		remove(source.c_str());
		return;
	}
	if (checkerForFile){
		if (rename(source.c_str(), newName.c_str()) != 0){
			throw exception("cant move or rename file!\n");
		}
	}
}