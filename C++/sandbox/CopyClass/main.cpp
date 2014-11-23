#include <iostream>
#include "sample.h"
using namespace std;
/*проверяем копирование данных из одного объекта в другой*/
int main() {
	int a=1, b=2, c=3, d=4;
    sample k(a, b);
    sample m(c, d);
    m=k;//проверка копирование данных из одного объекта в другой
    k.print();
    m.print();
    return 0;
}
