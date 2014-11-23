#include "header.h"
#include "stats.h"
#include "compare.h"
void debtorGroupDisp(exam* p)
{
    /*вывод всех студентов с задолженностью отсортированных по группам и по алфавиту внутри группы,
    функция так же выводит список только тех предметов которые не сданы студентом*/
    qsort(p, NUM_OF_STUDENTS, sizeof(exam), compareGroup);//сортируем по группам
    int (*stats[])(exam*)= {statusDerm, statusEpid, statusGig, statusC };
    char* subj[]= {"\tДерматовенерология: ", "\tЭпидемиология: ", "\tГигиена: ", "\tЯзык программирования Си: "};
    for(int i=0; i<NUM_OF_STUDENTS; ++i)//цикл перебирает всех студентов
    {
        if((p+i)->derm==0||(p+i)->epid==0||(p+i)->gig==0||(p+i)->c==0)
        {
            cout<<"\tФамилия: "<<(p+i)->name<<endl;
            cout<<"\tГруппа: "<<(p+i)->group<<endl;
            for(int j=0; j<4; ++j)//цикл смотрит по каким именно предметам задолжал студент
            {
                if(stats[j](p+i))
                {
                    cout<<subj[j]<<"Не сдал"<<endl;
                }
            }
            cout<<endl;
        }
    }
}
