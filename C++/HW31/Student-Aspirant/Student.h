#pragma once
#include <iostream>
#include <string>
using namespace std;


class Student
{
public:
	Student();
	Student(int, char, string);
	virtual ~Student();
	virtual void show();
protected:
	int age;
	char sex;
	string name;
};

