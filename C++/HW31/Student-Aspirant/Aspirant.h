#pragma once
#include "Student.h"

class Aspirant : public Student
{
public:
	Aspirant();
	Aspirant(int, char, string, string);
	virtual ~Aspirant();
	virtual void show();
protected:
	string scientific_work;
};

