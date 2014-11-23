#include "String.h"
#include "main.h"
using namespace std;
/*2. Разработать класс String, который в дальнейшем будет использоваться для
работы со строками. Класс должен содержать:
      конструктор по умолчанию, позволяющий создать строку длиной 80
      символов;
      конструктор, позволяющий создавать строку произвольного размера;
      конструктор, который создаёт строку и инициализирует её строкой,
      полученной от пользователя.
Класс должен содержать методы для ввода строк с клавиатуры и вывода
строк на экран.*/
int main() {
    cout << "\tВыберите опцию" << endl;
    cout<<"\t1 - создать строку длиной 80 символов\n\t2 - создать строку с заданным размером\n\t3 - копирование строки\n";
    int opt;
    void (*menu[])()= {defaultString, initString, copyString};
    cin>>opt;
    if(opt>=1&&opt<=3) {
        menu[opt-1]();
    } else {
        cout<<"\tНеверная опция, повторите ввод\n";
    }
    return 0;
}
