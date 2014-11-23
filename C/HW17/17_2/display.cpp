#include "header.h"
void display(exam *p)
{
    char* status[]= {"Задолженность", "Сдано"};
    char* subj[]= {"\tДерматовенерология: ", "\tЭпидемиология: ", "\tГигиена: ", "\tЯзык программирования Си: "};
    cout<<"\tФамилия: "<<p->name<<endl;
    cout<<"\tГруппа: "<<p->group<<endl;
    cout<<subj[DERM]<<status[p->derm]<<endl;
    cout<<subj[EPID]<<status[p->epid]<<endl;
    cout<<subj[GIG]<<status[p->gig]<<endl;
    cout<<subj[C]<<status[p->c]<<endl<<endl;
}
void displayAll(exam *p)
{
    /*вывод всех студентов вообще*/
    for(int i=0; i<NUM_OF_STUDENTS; ++i)
    {
        display(p+i);
    }
}
