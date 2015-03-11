#include "FileManager.h"
void copyAllFiles(const string source, const string destination){
	_finddata_t *fileinfo = new _finddata_t;
	_finddata_t *same_fileinfo = new _finddata_t;//существует в новой директории файл с таким же именем?
	int checker = 1, indicatorOfSameFile, done;
	string src_mask = parser(source);
	done = _findfirst(src_mask.c_str(), fileinfo);
	if (done == -1){
		throw exception("source directory is not found!\n");
	}
	//переход по самой корневой директории
	while ((strcmp(fileinfo->name, ".") == 0) || (strcmp(fileinfo->name, "..") == 0)){
		checker = _findnext(done, fileinfo);
	}
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
		/*если поддиректория была последней, то наш чекер изменится и мы не должны пытаться прочитать поддиректорию в потоке ввода*/
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
	_findclose(indicatorOfSameFile);
	delete fileinfo;
	delete same_fileinfo;
}
void copyFile(const string source, const string destination){
	_finddata_t *fileinfo = new _finddata_t;
	_finddata_t *same_fileinfo = new _finddata_t;
	int done = 1, indicatorOfSameFile = 1, checkerForFile = 0, checkerForDir = 0;
	done = _findfirst(source.c_str(), fileinfo);
	if (done == -1){//проверяем существует ли исходный файл
		throw exception("cant open file!\n");
	}
	string dst_mask = parser(destination);
	indicatorOfSameFile = _findfirst(dst_mask.c_str(), same_fileinfo);
	if (indicatorOfSameFile == -1){//проверяем существует ли в принципе директория в которую мы собираемся скопировать файл
		throw exception("cant open destination directory!\n");
	}
	string newName = destination + fileinfo->name;//формируем имя копии
	ifstream fin;
	ofstream fout;
	char buff[_MAX_PATH];
	indicatorOfSameFile = _findfirst(newName.c_str(), same_fileinfo);
	if (indicatorOfSameFile != -1){//проверяем существует такой же файл в другой директории
		if (answer(same_fileinfo)){//если существует спрашиваем че делать. если добро-переписываем
			checkerForFile = 1;//делаем чекер положительным для файла и для папки, либо чекер останется 0
			checkerForDir = 1;
		}
	}
	else{
		checkerForFile = 1;//если не уществует все чекеры делаем положительными
		checkerForDir = 1;
	}

	if (fileinfo->attrib &_A_SUBDIR && checkerForDir != 0) {
		//правило для копирования папки, мы уже спросили заранее заменить или нет, теперь копируем
		//все файлы из подпапки. Если правило отработало цикл для копирвоания файла не запуститься
		mkdir(newName.c_str());
		copyAllFiles(source + "\\", newName + "\\");
		return;//досрочно выходим из функции т.к чекер уже положительный а переписывать папку в потоке вывода нам нельзя
	}

	if (checkerForFile){
		fin.open(source, ios::binary);
		fout.open(newName, ios::binary);
		if (!fin.is_open()){
			throw exception("cant open file!\n");
		}
		fin.read(buff, sizeof(char));
		while (!fin.eof()){
			fout.write(buff, sizeof(char));
			fin.read(buff, sizeof(char));
		}
	}
	_findclose(done);
	_findclose(indicatorOfSameFile);
	delete same_fileinfo;
	delete fileinfo;
}