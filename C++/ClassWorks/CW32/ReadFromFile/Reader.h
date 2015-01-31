#pragma once
#include <iostream>
#include <exception>
#include <fstream>
#include <string>
using namespace std;

class Reader
{
public:
	Reader(const string&);
	virtual ~Reader();
	string name;
	ifstream fin;
	void read();

};

