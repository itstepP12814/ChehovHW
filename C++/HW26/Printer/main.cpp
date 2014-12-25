#include <iostream>
#include "Client.h"
#include "Printer.h"
using namespace std;
/*Разработать приложение, имитирующее очередь печати принтера.
Должны быть клиенты, посылающие запросы на принтер, у каждого из которых есть свой приоритет.
Каждый новый клиент попадает в очередь в зависимости от своего приоритета.
Необходимо сохранять статистику печати (пользователь, время) в отдельной очереди. Предусмотреть вывод статистики на экран.*/

int main() {
    Client A(8, 10);
    Client B(9, 12);
    Client C(6, 15);
    Client D(5, 14);
    Client E(7, 11);
    Client F(12, 12);
    Printer P(3);
    P.setQueue(A);
    P.setQueue(C);
    P.setQueue(B);
    P.setQueue(D);
    P.setQueue(E);
    P.setQueue(F);
    P.print();
    return 0;
}
