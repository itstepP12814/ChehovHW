#include "main.h"
void calculate(double dig1, double dig2, char sgn) {
    double res;
    switch (sgn) {
    case '+':
        res=dig1+dig2;
        break;
    case '-':
        res=dig1-dig2;
        break;
    case '*':
        res=dig1*dig2;
        break;
    case '/':
        res=dig1/dig2;
        break;
    default:
        break;
    }
    cout<<res;
}
