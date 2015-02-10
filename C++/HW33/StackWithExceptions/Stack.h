#pragma once
#include <iostream>
#include <exception>
using namespace std;
class Stack
{
public:
	Stack();
	virtual ~Stack();
	bool isFull();
	bool isEmpty();
	int deleteElement();
	void pushFront(int);
	void show();
private:
	int* stck;
	int size;
	int counter;
};

