#include "header.h"
void genreSort(int size, video *p)
{
    int choice, a;
    genre array[3]= {comedy, fantasy, fantastic};
    cout<<"\tВыбери нужный жанр\n";
    cout<<"\t1 - COMEDY, 2 - FANTASY, 3 - FANTASTIC\n";
    cin>>choice;
    --choice;//получаем человечкский индекс элемента;
    while(a)
    {
        if(choice<=2&&choice>=0)
        {
            for(int i=0; i<size; ++i)
            {
                if((p+i)->gnr==array[choice])
                {
                    if((p+i)->rt==cool) result(p+i);
                    cout<<endl;
                }
            }
            break;
        }
    }
}
void highRate(int size, video *p)
{
    for(int i=0; i<size; ++i)
    {
        if((p+i)->rt==cool||(p+i)->rt==norm) result(p+i);
    }
}
