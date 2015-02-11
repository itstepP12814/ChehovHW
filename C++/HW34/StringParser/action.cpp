#include "Header.h"

double action(const double digits [], int size_of_digits,const char sign[], int size_of_signs){
	double res;
	for (int i = 0; i < size_of_signs; ++i){
		switch (sign[i]){
		case '*': res=digits[i] * digits[i + 1];
			break;
		case '/':
		}
	}
	return res;
}