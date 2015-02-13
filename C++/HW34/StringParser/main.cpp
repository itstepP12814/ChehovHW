#include "StringParser.h"
/*Задание требовало распарсить строку типа string и вычислить выражение например (2+3)*4+1. Снаскоку задачку решить не получилось.
Поиски привели меня к статье о обратной польской записи на википедии, там же был подсмотрен алгоритм, в папку sandbox добавлен скопипащенный код, вдруг пригодится.
По факту решение было взято отсюда http://algolist.manual.ru/maths/misc/revpn.php, алгоритм и принцип расстановки приоритета операторов,но сам код написан самостоятельно с нуля.
*/
int main(){
	char answer;
	string str, out;
	double result;
	do{
		cout << "Enter the math expression" << endl;
		cin >> str;
		out = '(' + str + ')';
		out = getPolishNotation(out);
		result = parser(out);
		cout << out << endl << result << endl;
		cout << "Do you want repeat again? y/n" << endl;
		cin >> answer;
	} while (answer == 'y' || answer == 'Y');
	return 0;
}