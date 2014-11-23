#include "compare.h"
#include "header.h"
int compareName(const void* a, const void* b)
{
    /*примечание для меня
    Функция принимает два указателя любого типа. Потом мы делаем явное преобразование указателя любого типа
    к указателю типа sonst exam* , и сразу же записываем в переменную такогоже типа(А) значение на которое ссылается
    указатель*/
    const exam A=*(const exam*)a;
    const exam B=*(const exam*)b;
    return strcmp(A.name, B.name);
}
int compareGroup(const void* a, const void* b)
{
    const exam A=*(const exam*)a;
    const exam B=*(const exam*)b;
    return (B.group - A.group);
}

