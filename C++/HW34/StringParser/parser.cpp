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
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')' || str[i]=='^'){//если не число
			//если стек пуст ложим знак в стек
			output += ' ';//т.к цифры закончились ложим в результирующую строку пробел для разделения цифр
			p = getPriority(str[i]);
			try{//тут мы проверяем можно ли добавить знак в стек и в зависимости от приоритета, метод compare может что-то выпихнуть из стека в строку
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
double parser(const string& str){//функция парсит результирующую польскую запись и считает само выражение
	double digits[10] = {};//массив для записи цифр по порядку следования в строке
	int dig_counter = 0;
	int i;
	double res;
	for (i = 0; i < str.length(); ++i){//данныы цикл ложит все цифры в Массив в порядке их следования в выражении
		if (str[i] <= '9'&&str[i] >= '0'){//если нам попалась первая цифра - берем число
			digits[dig_counter] = atof(&str[i]);
			++dig_counter;//количество цифр в массиве
			while (str[i] != ' '){//когда положили число идем до первого пробела, для того чтобы не ложить лишние знаки числа как цифры
				++i;
			}
		}
		else {
			if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i]=='^'){
				try{
					res = action(digits[dig_counter - 2], digits[dig_counter - 1], str[i]);//считаем действие двух операндов
				}
				catch (exception ex){
					cout << ex.what();
				}
				digits[dig_counter - 2] = res;//заменяем оба числа в массиве - результатом вышележащего вычисления
				digits[dig_counter - 1] = 0;//
				dig_counter--;//количество цифр в массиве уменьшилось на 1 в результате совершения операции над двумя элементами массива
			}
		}
	}
	return res;
}
int getPriority(char c){
	switch (c){
	case '^':return 4;
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
	case '/': return dig1 / dig2;
	case '^': return pow(dig1, dig2);
	default: throw exception("error with operator!\n");
	}
}