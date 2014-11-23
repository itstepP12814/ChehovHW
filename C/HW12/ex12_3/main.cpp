#include "functions.h"
int main()
{
    const int size=10;
    int A[size];
    int B[size];
    int AB[2*size];
    int commElements[2*size];
    int notA[size];
    int notB[size];
    int notAB[size];
    generateA(A, size);
    generateB(B, size);
    cout<<"массив А\n";
    display(A, size);
    cout<<"массив В\n";//возвращает индекс последнего элемента в массиве заполненном общими элементами
    display(B, size);
    generateCommon(A, B, AB, size, size);
    cout<<"объединенный массив\n";
    display(AB, 2*size);
    int sizeCE = searchCommElements(A, B, commElements, size);//записываем величину последнего необходимого элемента в массиве с общими числами.
    cout<<"массив из общих элементов двух предыдущих\n";
    display(commElements, sizeCE);
    int sizeNotB= notInclude(commElements, notB, A, sizeCE, size);//индекс последнего элемента массива А, не включающего элементы В
    cout<<"массив А не включающий элементы В\n";
    display(notB, sizeNotB);
    int sizeNotA=notInclude(commElements, notA, B, sizeCE, size);//индекс последнего элемента массива В не включающего элементы А
    cout<<"массив В не включающий элементы А\n";
    display(notA, sizeNotA);
    cout<<"элементы массивов А и В, которые не являются общими для них\n";
    generateCommon(notA, notB, notAB, sizeNotA, sizeNotB);
    display(notAB, sizeNotA+sizeNotB);
    return 0;
}
void display(int *a, int size)
{
    for(int i=0; i<size; ++i, ++a)
    {
        cout<<*a<<" ";
    }
    cout<<"\n\n";
}
