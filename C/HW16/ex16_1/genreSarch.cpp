#include "header.h"
void genreSearch(int size, video *p)
{
    int choice, a=1;
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
                    result(p+i);
                    cout<<endl;
                }
            }
            break;
        }
        else cout<<"\tНеверная опция. Повторите ввод\n";
    }
}
