#include "neg_element_sorting.h"
int main()
{
    srand(time(NULL));
    const int size=10;
    //int array[size]={18, 1, -14, -16, -20, 5, 17, 16, 19, -15};
    int array[size];
    cout<<"\tнеотсортированный массив\n";
    display(array, size);
    cout<<endl<<endl;
    negativeElementSorting(array, size);
    cout<<"\tотсортированный массив\n";
    display(array, size);
    return 0;
}

