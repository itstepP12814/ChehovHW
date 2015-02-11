#include "Header.h"

void parser(const string& str){
	double digits[10] = {};//массив для записи цифр по порядку следования в строке
	double res;
	char signs[12] = {};//записи знаков
	int iterator_sign = 0, iterator_dig = 0;
	int len = str.length();
	int i, j;
	for (i = 0; i < len; ++i){//данныы цикл ложит все цифры в стек в порядке их следования в выражении
		if (str[i] <= '9'&&str[i] >= '0'){
			digits[iterator_dig] = atof(&str[i]);
			++iterator_dig;
			while (str[i] <= '9'&&str[i] >= '0'){
				++i;
			}
		}
	}
	for (j = 0; j < len; ++j){//ложим все знаки в порядке следования в стек
		if (str[j] == '+' || str[j] == '-' || str[j] == '*' || str[j] == '/' || str[j]=='('||str[j]==')'){
			signs[iterator_sign] = str[j];
			++iterator_sign;
		}
	}
}

double expressionInBrackets(const string& str){
	double res;
	return res;
}