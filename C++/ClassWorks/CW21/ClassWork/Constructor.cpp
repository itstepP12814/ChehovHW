#include <iostream>
using namespace std;
class Mammal { //абстрактный общий родительский класс
    // public:
protected:
    string name; //поле недоступно извне
public:
    void voice();
    Mammal();
    Mammal (string n); //вызываем констуктор
    Mammal(const Mammal);
    ~Mammal();//деструктор

    string getName() {
        return name;   //делаем функцию для отображения имени при доступе извне для name
    }
    void setName(string newName) {
        name = newName;
    }
};
Mammal::Mammal(string n) { //обьявление конструктора
    name = n;
}
Mammal::Mammal(const Mammal &source) {
    cout<<"a copy of "<<source.name<<" was born";
}
Mammal::~Mammal() { //объявление деструктора
}
class  Cat {
public:
    Cat();
    ~ Cat();
    const string n;
    void greetAnotherCat(Cat guest) {
        cout << "Cat " <<n<< " says hello to " << guest.n << endl;
    }
};
Cat::Cat() : Mammal(), n("LOL") { //Список инициализаторов здесь можно вызвать конструкторы и задать значения для констант
    cout << "A cat was born\n";
}
