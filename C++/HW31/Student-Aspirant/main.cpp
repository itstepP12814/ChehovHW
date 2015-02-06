#include "Student.h"
#include "Aspirant.h"
/*немного не понял смысла делать виртуальный метод virtual show, ведь можно написать обычный метод 
show для класса студента и одноименный метод для класса аспиранта, во время вызова метода для аспиранта вызоветса именно его метод, какой тогда
смысл писать virtual???*/
int main(){
	Student A(18, 'm', "vasya");
	A.show();
	Aspirant B(22, 'm', "vova", "biology");
	B.show();
	return 0;
}