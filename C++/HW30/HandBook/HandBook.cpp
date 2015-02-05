#include "HandBook.h"


HandBook::HandBook() : root(NULL)
{
}


HandBook::~HandBook()
{
}
void HandBook::createFirm(string nm, string own, string tl, string addr, string cr){
	if (root == NULL){
		root = new Company(nm, own, tl, addr, cr);
	}
	else {
		Company** current = &root;
		while ((*current)->next != NULL){
			current = &(*current)->next;
		}
		Company* cm = new Company(nm, own, tl, addr, cr);
		cm->prev = (*current);
		cm->prev->next = cm;
		cm->next = NULL;
	}
}
void HandBook::show(){
	if (root == NULL){
		cout << "error" << endl;
	}
	else {
		Company** current = &root;
		while (*current != NULL){
			cout << (*current)->name << endl;
			current = &(*current)->next;
		}
	}
}
void HandBook::save(){
	ofstream fout("save.csv", ios::binary | ios::out);
	if (!fout.is_open()){
		cout << "error";
		return;
	}
	Company** current = &root;
	while (*current != NULL){
		fout << "\"" << (*current)->name << "\"; ";
		fout << "\"" << (*current)->owner << "\"; ";
		fout << "\"" << (*current)->tel << "\"; ";
		fout << "\"" << (*current)->address << "\"; ";
		if ((*current)->next == NULL){//чтобы не писать в конец лишний пробле и новую строку
			fout << "\"" << (*current)->career << "\";";
		}
		else {
			fout << "\"" << (*current)->career << "\"; " << endl;
		}
		current = &(*current)->next;
	}
	fout.close();
}
void HandBook::search(const string key, const string mode){
	if (root == NULL){
		cout << "error\n";
		return;
	}
	Company** current = &root;
	if (mode == "name"){
		while (*current != NULL){
			if ((*current)->name == key){
				cout << "find!\n" << (*current)->name << endl;
				return;
			}
			current = &(*current)->next;
		}
	}
	if (mode == "tel"){
		while (*current != NULL){
			if ((*current)->tel == key){
				cout << "find!\n" << (*current)->name << endl;
				return;
			}
			current = &(*current)->next;
		}
	}
	if (mode == "owner"){
		while (*current != NULL){
			if ((*current)->owner == key){
				cout << "find!\n" << (*current)->name << endl;
				return;
			}
			current = &(*current)->next;
		}
	}
	if (mode == "career"){
		while (*current != NULL){
			if ((*current)->career == key){
				cout << "find!\n" << (*current)->name << endl;
				return;
			}
			current = &(*current)->next;
		}
	}
}
void HandBook::read(){
	ifstream fin("save.csv", ios::binary);
	string name;
	string owner;
	string tel;
	string address;
	string career;
	if (!fin.is_open()){
		cout << "error";
	}
	while (!fin.eof()){
		fin >> name;
		fin >> owner;
		fin >> tel;
		fin >> address;
		fin >> career;
		createFirm(name, owner, tel, address, career);
	}
	fin.close();
}