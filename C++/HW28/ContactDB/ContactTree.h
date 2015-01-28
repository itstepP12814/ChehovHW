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
		string number;
		string name;
		Subscriber* left;
		Subscriber* right;
		Subscriber* parent;
		Subscriber(const string& index) :name(index), left(NULL), right(NULL), parent(NULL) {}
		~Subscriber() {}
	};
	//////////////////////////////////////////
	string& operator[](const string&);
	void editNumber(const string&, const string&, Subscriber*);
	void editName(const string&, const string&, Subscriber*);
	Subscriber* searchByName(const string&);
	void searchByNumber(const string&, Subscriber*);
	void deleteContact(const string&);
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

