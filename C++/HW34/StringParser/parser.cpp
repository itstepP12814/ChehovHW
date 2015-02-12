#include "StringParser.h"
string getPolishNotation(const string& str){//делаем польскую нотацию
	Stack st;
	string output;
	int p;
	for (int i = 0; i < str.length(); ++i){
		if ((str[i] <= '9'&& str[i] >= '0') || str[i] == ' '){
			//ложим цифру в строку
			output += str[i];
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')'){//если не число
			//если стек пуст ложим знак в стек
			output += ' ';//т.к цифры закончились ложим в результирующую строку пробел для разделения цифр
			p = prior(str[i]);
			try{//тут мы проверяем можно ли добавить знак в стек и в зависимости от приоритета compare может что-то выпихнуть из стека в строку
				if (st.isEmpty()){
					st.pushFront(str[i]);
				}
				else {
					st.compare(p, output);
					st.pushFront(str[i]);
				}
			}
			catch (exception ex) {
				cout << ex.what();
			}
		}
	}
	return output;
}
double parser(const string& str){
	double digits[10] = {};//массив для записи цифр по порядку следования в строке
	int iterator_dig = 0;
	int i;
	double res;
	for (i = 0; i < str.length(); ++i){//данныы цикл ложит все цифры в Массив в порядке их следования в выражении
		if (str[i] <= '9'&&str[i] >= '0'){//если нам попалась первая цифра - берем число
			digits[iterator_dig] = atof(&str[i]);
			++iterator_dig;//количество цифр в массиве
			while (str[i] != ' '){//когда положили число идем до первого пробела, для того чтобы не ложить лишние знаки числа как цифры
				++i;
			}
		}
		else {
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
				try{
					res = action(digits[iterator_dig - 2], digits[iterator_dig - 1], str[i]);//считаем действие двух операндов
				}
				catch (exception ex){
					cout << ex.what();
				}
				digits[iterator_dig - 2] = res;//заменяем оба числа в массиве - результатом вышележащего вычисления
				digits[iterator_dig - 1] = 0;//
				iterator_dig--;//количество цифр в массиве уменьшилось на 1 в результате совершения операции над двумя элементами массива
			}
		}
	}
	return res;
}
int prior(char c){
	switch (c){
	case '*':
	case '/': return 3;
	case '-':
	case '+': return 2;
	case '(': return 1;
	case ')': return 0;
	default: return -1;
	}
}
double action(double dig1, double dig2, char sign){
	switch (sign)
	{
	case '+': return dig1 + dig2;
	case '-': return dig1 - dig2;
	case '*': return dig1*dig2;
	case '/':return dig1 / dig2;
	default: throw exception("error with operator!\n");
	}
}