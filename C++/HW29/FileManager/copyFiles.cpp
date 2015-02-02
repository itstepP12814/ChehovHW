#include "FileManager.h"
void copyAllFiles(string source, string destination){
	_finddata_t *fileinfo = new _finddata_t;
	_finddata_t *same_fileinfo = new _finddata_t;//существует в новой директории файл с таким-же именем?
	int checker, indicatorOfSameFile, done;
	string mask = source + "*.*";
	done = _findfirst(mask.c_str(), fileinfo);
	if (done == -1){
		throw exception("source directory is not found!\n");
	}
	checker = _findnext(done, fileinfo);
	checker = _findnext(done, fileinfo);
	string oldName = source;
	string newName = destination;
	char buff[_MAX_PATH];
	ifstream fin;
	ofstream fout;
	while (checker != -1){

		while (fileinfo->attrib &_A_SUBDIR && checker != -1){//рекурсивный вызов если нам встретилась поддериктория внутри папки
			string src = source + fileinfo->name + "\\";
			string dst = destination + fileinfo->name;
			if (_findfirst(dst.c_str(), same_fileinfo) != -1){ //если нам встретилась поддиректория с таким же названием, как в источнике - спрашиваем че делать
				if (answer(same_fileinfo)){//если говорят заменить добавляем к строке два // чтобы получить путь к папке, и запускаем рекурсию
					dst += "\\";
					mkdir(dst.c_str());
					copyAllFiles(src, dst);
				}
			}
			else { //если одинаковая поддиректория не встретилась - создаем новую
				dst += "\\";
				mkdir(dst.c_str());
				copyAllFiles(src, dst);
			}
			checker = _findnext(done, fileinfo);
		}
		/*если поддиректория была последней, то наш чекер измениться и мы не должны пытаться прочитать поддиректорию в потоке ввода*/
		if (checker != -1){
			indicatorOfSameFile = 1;
			oldName += fileinfo->name;
			newName += fileinfo->name;
			if (_findfirst(newName.c_str(), same_fileinfo) != -1){
				indicatorOfSameFile = answer(same_fileinfo);
			}
			if (indicatorOfSameFile){//если имена файлов совпадают мы их спросим и можем заменить, если нет, то условие выполнится по умолчанию
				fin.open(oldName, ios::binary);
				fout.open(newName, ios::binary);
				if (!fin.is_open()){
					throw exception("cant open file!\n");
				}
				fin.read(buff, sizeof(char));//для того чтобы не писать в конец лишний байт
				while (!fin.eof()){
					fout.write(buff, sizeof(char));
					fin.read(buff, sizeof(char));
				}
				fin.close();
				fout.close();
				newName = destination;
				oldName = source;
			}
			checker = _findnext(done, fileinfo); //независимо от того заменили мы файл или нет - переходим к поиску след файла
		}
	}
	_findclose(done);
	delete fileinfo;
	delete same_fileinfo;
}
int answer(const _finddata_t* fileinfo){
	int indicatorOfSameFile;
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