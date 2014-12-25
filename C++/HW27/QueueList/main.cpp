#include <iostream>
#include <QueueList.h>
using namespace std;
/*Реализовать шаблонный класс "Очередь" на основе двусвязного списка. */
int main()
{
    QueueList<int> L;
    cout<<sizeof(L)<<endl;
    L.add(15);
    return 0;
}
