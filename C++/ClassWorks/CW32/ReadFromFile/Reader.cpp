#include "Reader.h"


Reader::Reader(const string& nameOfFile) :name(nameOfFile), fin(nameOfFile)
{
	/*т. к объект ридер должен содержать внутри себя объекты классов стринг и ifstream, то мы должны еще
	до создания объекта ридер иметь где-то в памяти стринг и поток ввода. Самый простой способ использовать
	список инициализации такиим образом сначала создается(инициалзируется) строка, а затем поток ввода, после
	чего создается сам объект ридер*/
}


Reader::~Reader()
{
}

void Reader::read(){
	string firstName;
	string lastName;
	if (name.find(".csv")==string::npos){//проверка корректности расширения файлы
		exception ex("file have uncorrectly extension\n");
		throw ex;
	}
	//т.к поток ввода был создан при создани оъекта мы не должны его открывать fin.open("string");
	if (!fin.is_open()){//проверка наличия самого файла
		exception ex("file if not found\n");
		throw ex;
	}
	while (!fin.eof()){
		fin >> firstName;
		fin >> lastName;
		cout << firstName << endl;
		cout << lastName << endl;
	}
	fin.close();
}