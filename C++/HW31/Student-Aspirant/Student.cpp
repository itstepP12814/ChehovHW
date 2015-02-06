#include "Student.h"

Student::Student()
{
}
Student::Student(int ag, char s, string nm) : age(ag), sex(s), name(nm) {

}

Student::~Student()
{
}
void Student::show(){
	cout << "name: " << name << endl;
	cout << "age: " << age << endl;
	cout << "sex: " << sex << endl;
}