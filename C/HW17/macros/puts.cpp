#include "header.h"
void puts()
{
    srand(time(NULL));
    char filename[]="sample";
    ofstream fout;
    fout.open(filename);
    for(int i=0; i<20; ++i)
    {
        fout<<rand()%5+1<<" sample text "<<endl;
    }
    fout.close();
}
