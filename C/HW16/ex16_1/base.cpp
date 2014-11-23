#include "header.h"
video *base()
{
    const int size=10;//размер массива
    video diamond_arm= {"БРИЛЛИАНТОВАЯ РУКА",  "ГАЙДАЙ", comedy, cool, 22900};
    video fifth_el= {"ПЯТЫЙ ЭЛЕМЕНТ", "БЕССОН", fantastic, norm, 30000};
    video avengers= {"МСТИТЕЛИ","УИДОН", fantastic, norm, 25000};
    video lor= {"ВЛАСТЕЛИН КОЛЕЦ", "ДЖЕКСОН", fantasy, cool, 35000};
    video hobbit= {"ХОББИТ", "ДЖЕКСОН", fantasy, cool, 35000};
    video resident_evil= {"ОБИТЕЛЬ ЗЛА", "АНДЕРСОН", fantastic, bad, 17000};
    video array[size]= {diamond_arm, fifth_el, avengers, lor, hobbit, resident_evil}, *p;
    p=array;
    return p;
}
