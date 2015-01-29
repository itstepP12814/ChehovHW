#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ContactTree
{
public:
	ContactTree();
	virtual ~ContactTree();

	struct Subscriber {
		int number;
		int name;
		Subscriber* left;
		Subscriber* right;
		Subscriber* parent;
		Subscriber(const int index) :name(index), left(NULL), right(NULL), parent(NULL) {}
		~Subscriber() {}
	};

	int& operator[](const int);
	Subscriber* searchByName(const int);
	void deleteContact(const int);
	void print(Subscriber*);
	void showFromLeft(Subscriber*);
	void showFromRight(Subscriber*);
	Subscriber* max(Subscriber*);
	Subscriber* min(Subscriber*);
	Subscriber* next(Subscriber*);
	Subscriber* prev(Subscriber*);
	friend Subscriber* getRoot(ContactTree*);
private:
	Subscriber* root;
	size_t sizeOfTree;
};
