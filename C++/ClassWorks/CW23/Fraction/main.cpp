#include <iostream>
#include "fraction.h"
using namespace std;

int main()
{
    Fraction A(3, 6);
    Fraction B(5);
    Fraction C=A*B;
    C.print();
    return 0;
}
