#include "functions.h"
int main()
{
    const int size =10;
    int arrayM[size];
    int arrayN[size];
    int arrayMN[2*size];
    generator(arrayM,size);
    generator1(arrayN,size);
    /* используются два генератора не спроста, т.к вначале была одна функция.
    Видимо передача и заполнение обоих массивов проходит в течение одной миллисекунды и
    потому, даже передавая оба массива одной функции, на выходе получается, что точка отсчета одна и та же, следовательно два абсолютно одинаковых массива.
    Чтобы этого избежать используется вторая функция в качестве точки отсчета там не srand, а srand48*/
    cout<<"массив M\n";
    display(arrayM, size);
    cout<<"массив N\n";
    display(arrayN, size);
    rewrite(arrayM, arrayN, arrayMN, size);
    cout<<"Общий массив\n";
    display(arrayMN, 2*size);
    sorting(arrayMN, 2*size);
    cout<<"упорядоченный массив\n";
    display(arrayMN, 2*size);
    return 0;
}
void display(int *m, int size)
{
    for(int i=0; i<size; ++i, ++m)
    {
        cout<<*m<<" ";
    }
    cout<<"\n\n";
}
