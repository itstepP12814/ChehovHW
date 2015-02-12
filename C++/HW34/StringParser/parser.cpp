#include "StringParser.h"
string parser(const string& str){
	Stack st;
	string output;
	string temp_str;
	int p;
	int len_in = str.length();
	for (int i = 0; i < len_in; ++i){
		if ((str[i] <= '9'&& str[i] >= '0')||str[i]==' '){
			//ложим цифру в строку
			output += str[i];
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')'){//если не число
			//если стек пуст ложим знак в стек
			p = prior(str[i]);
			if (st.isEmpty()){
				st.pushFront(str[i]);
			}
			else {
				st.compare(p, output);
				st.pushFront(str[i]);
			}
		}
	}
	return output;
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
