#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <exception>
using namespace std;

string getPolishNotation(const string&);
double parser(const string&);
int prior(char);
double action(double, double, char);

class Stack{
public:
	Stack() : size(12), counter(0){
		stck = new char[size];
	}
	virtual ~Stack(){}
	char* stck;
	int size;
	int counter;
	bool isFull();
	bool isEmpty();
	void pushFront(char c);
	void compare(int, string&);
};

