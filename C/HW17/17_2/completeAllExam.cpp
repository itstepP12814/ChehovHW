#include "header.h"
void completeAllExam(exam *p)
{
    /*вывод всех студентов без задолженностей*/
    for(int i=0; i<NUM_OF_STUDENTS; ++i)
    {
        if((p+i)->derm==1&&(p+i)->epid==1&&(p+i)->gig==1&&(p+i)->c==1)
        {
            display(p+i);
        }
    }
}
