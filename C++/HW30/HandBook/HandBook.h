#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class HandBook
{
public:
	HandBook();
	virtual ~HandBook();
	struct Company {
		string name;
		string owner;
		string tel;
		string address;
		string career;
		Company* next;
		Company* prev;
		Company(string& nm, string& own, string& tl, string& addr, string& cr) : name(nm),
			owner(own), tel(tl), address(addr), career(cr), next(NULL), prev(NULL) {}
	};
	void createFirm(string nm, string own, string tl, string addr, string cr);
	void show();
	void save();
	void search(const string, const string);
	void read();
	Company* root;
};