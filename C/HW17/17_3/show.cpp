#include "header.h"
void show(my_tm* p, int slot)
{
    cout<<"\tСлот № "<<slot+1<<endl;
    cout<<"\tЧасы\n"<<"\t"<<p->hour<<endl;
    cout<<"\tМинуты\n"<<"\t"<<p->min<<endl;
    cout<<"\tСекунды\n"<<"\t"<<p->sec<<endl<<endl;
}
void showAll(my_tm* p)
{
    int slot=0;
    for(int i=0; i<SIZE; ++i) show((p+i), slot);
}
