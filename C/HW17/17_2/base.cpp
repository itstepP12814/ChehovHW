#include "header.h"
#include "compare.h"
exam* base()
{
    exam a= {"Барашкова", 589, 1, 1, 1, 0};
    exam b= {"Сорока", 589, 1, 1, 1,1};
    exam c= {"Куранец", 589, 1, 1, 1, 0};
    exam d= {"Чехов", 588, 1, 1, 0,1};
    exam e= {"Шмелев", 588, 1, 1, 1,0};
    exam f= {"Белявская", 587, 1, 1, 1,0};
    exam g= {"Мирончук", 587, 1, 0, 0, 0};
    static exam array[NUM_OF_STUDENTS] = {a, b, c, d, e, f, g}, *p;
    qsort(array, NUM_OF_STUDENTS, sizeof(exam), compareName);//сразу же отсортировываем массив по алфавиту
    p=array;
    return p;
}
