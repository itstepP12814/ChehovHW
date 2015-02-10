#include "Stack.h"
Stack::Stack() :counter(0), size(10), stck(NULL)
{
	stck = new int[size];
	if (stck == NULL) throw exception("error memory\n");
}


Stack::~Stack()
{
	delete[]stck;
}

bool Stack::isFull(){
	if (counter < size){
		return false;
	}
	else {
		if (counter == size){
			return true;
		}
		else throw exception("stack overflow\n");
	}
}
bool Stack::isEmpty(){
	if (counter == 0){
		return true;
	}
	else{
		if (counter > size){
			throw exception("stack overflow\n");
		}
		else return false;
	}
}
void Stack::pushFront(int d){
	if (!isFull()){
		stck[counter] = d;
		++counter;
	}
	else cout << "stack is fool!\n";
}
int Stack::deleteElement(){
	//мы удаляем всегда последний добавленный элемент, у которого индекс равен counter-1
	//элемент остался лежать в памяти, но мы сдвинули казатель на -1, и таким образом мы можем перезаписать элемент при необходимости
	if (!isEmpty()){
		counter -= 1;
		return stck[counter];
	}
	else {
		cout << "stack is empty!\n";
		return 0;
	}
}
void Stack::show(){
	for (int i = 0; i < counter; ++i){
		cout << stck[i] << endl;
	}
}