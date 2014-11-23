#include "header.h"
#include "stats.h"
int statusDerm(exam* p)
{
    if((p->derm)==0) return 1;
    else return 0;
}
int statusEpid(exam* p)
{
    if((p->epid)==0) return 1;
    else return 0;
}
int statusGig(exam* p)
{
    if((p->gig)==0) return 1;
    else return 0;
}
int statusC(exam* p)
{
    if((p->c)==0) return 1;
    else return 0;
}
