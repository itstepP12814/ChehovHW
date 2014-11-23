#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "String.h"
using namespace std;
/*создать функцию возвращающее случайное имя* типа String randomName(); */
String randomName() {
	srand(time(NULL));
	int ran=rand()%6;
	char* names[]={"Ori","Dori","Nori", "Bofur", "Bombur", "Bifur"};
	String x(names[ran]);
	return x;
}
int main() {
    String x("hello"), y(x);//создаем объект с строкой hello и объект y принмиающий значение из объекта х
    x.printToStream(cout);
    /*мы передаем методу printToStream() объект, cout, который принадлежит родительскому классу ostream,
    этому же классу принадлежат классы ofstream и их объекты, например вместо объекта cout мы можем
    передать объект класса ofstream obj; будет выглядеть как ofstream jbj;  x.printToStram(obj); Конечно, мы могли
    в методе принт использовать по умолчанке сиоут, но это было бы не универсально, а так мы с помощью большого класса разных объектов
    можем использовать printToStream для записи в файл и тэдэ*/
    cout<<endl;
    String k(randomName());
    k.printToStream(cout);
    return 0;
}
