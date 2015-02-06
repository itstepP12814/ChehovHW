#include <iostream>
#include <string>
using namespace std;

class Passport{
public:
	Passport(){}
	Passport(int ag, char s, string nm, string nb) : age(ag), sex(s), name(nm), number(nb) {}
	virtual ~Passport(){}
	/*немного не понял смысла делать виртуальный метод virtual show, ведь можно написать обычный метод
	show для класса обычного паспорта и одноименный метод для класса заграничного паспорта, во время вызова метода для загранпаспорта вызовется именно его метод, какой тогда
	смысл писать virtual???*/
	virtual void show(){
		cout << "age: " << age << endl;
		cout << "name: " << age << endl;
		cout << "sex: " << sex << endl;
		cout << "number: " << number << endl;
	}
	int getAge(){
		return age;
	}
	char getSex(){
		return sex;
	}
	string getName(){
		return name;
	}
protected:
	int age;
	char sex;
	string name;
	string number;
};
class ForeignPassport :public Passport {
public:
	ForeignPassport(){}
	ForeignPassport(Passport& A, string nb) : foreign_number(nb){
		age = A.getAge();
		sex = A.getSex();
		name = A.getName();
	}
	virtual void show(){
		cout << "age: " << age << endl;
		cout << "name: " << age << endl;
		cout << "sex: " << sex << endl;
		cout << "foreign number: " << foreign_number<< endl;
	}
protected:
	string foreign_number;
};

int main(){
	Passport A( 18, 'm', "vasya", "123456789");
	ForeignPassport B(A, "50852468");
	B.show();
	return 0;
}