#include "Header.h"

void parser(const string& str){
	double res1 = expressionInBrackets(str);

}
double expressionInBrackets(const string& str){
	double digits[5];//массив для записи цифр по порядку следования в строке
	double res;
	char signs[5];//записи знаков
	int iterator_char = 0, iterator_dig = 0;
	int bracket1 = str.find('(');//ищем вхождение первой скобки
	int bracket2;
	if (bracket1 != str.npos){
		bracket2 = str.rfind(')');//ищем вторую
		if (bracket2 == str.npos){
			throw exception("right bracket missing!\n");
		}
	}
	digits[iterator_dig] = atof(&str[bracket1 + 1]);//получение первого числа в строке
	++iterator_dig;
	for (int i = bracket1; i < bracket2; ++i){
		if (str[i] == '*' || str[i] == '/' || str[i] == '+' || str[i] == '-'){
			signs[iterator_char] = str[i];
			digits[iterator_dig] = atof(&str[i + 1]);
			++iterator_dig;
			++iterator_char;
		}
	}
	res = action(digits, iterator_dig, signs, iterator_char);
}