#include "header.h"
#include"stats.h"
#include "compare.h"
void debtorSubjectsDisp(exam* p)
{
    /*показ задолженность по группам попредметно*/
    char* subj[]= {"\tДерматовенерология: ", "\tЭпидемиология: ", "\tГигиена: ", "\tЯзык программирования Си: "};
    int (*stats[])(exam*)= {statusDerm, statusEpid, statusGig, statusC };
    int student_id;
    for(int j=0; j<NUM_OF_SUBJECTS; ++j)
    {
        for(int i=0; i<NUM_OF_STUDENTS; ++i)
        {
            if(stats[j](p+i))
            {
                cout<<subj[j]<<endl;
                cout<<"\tФамилия: "<<(p+i)->name<<endl;
                cout<<"\tГруппа: "<<(p+i)->group<<endl;
                cout<<endl;
            }
        }
    }
}
