#include "sorting.h"

using namespace std;
int main()
{
    const int SIZE=10;
    int chief=1;//параметр отвечающий за сортировку массива по возрастанию или по убыванию
    int array[SIZE];
    cout<<"\tвведи любые 10 чисел для сортировки"<<endl;
	input(array, SIZE);
    cout<<"\tвыбери тип сортировки 1 - по возрастанию 2 - по убыванию\n";
    cin>>chief;
    sorting(array, SIZE, chief);
    return 0;
}
