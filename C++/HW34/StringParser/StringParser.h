#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

string parser(const string&);
int prior(char);

class Stack{
public:
	Stack() : size(12), counter(0){

	}
	virtual ~Stack(){

	}
	char stck[12];
	int size;
	int counter;
	bool isFull();
	bool isEmpty();
	void pushFront(char c);
	void show();
	void compare(int, string&);
};

