#include "header.h"
void merge_sort(int array[], int l, int r)
{
    if(l<r)
    {
        merge_sort(array, l, (l+r)/2);
        merge_sort(array,(l+r)/2+1, r);
        int right[10];
        int left[10];
        int m,n,j,i,k;
        i=0;
        int lim=(l+r)/2;
        for(m=0; m<lim+1; ++m)
        {
            left[m]=array[l+m];
            ++i;
        }
        for(n=0; n<r-lim; ++n)
        {
            right[n]=array[lim+1+n];
            ++i;
        }
        i=l;
        j=0;
        k=0;
        while(j<lim-l+1&&k<r-lim)
        {
            if(left[j]<right[k])
            {
                array[i]=left[j];
                ++j;
            }
            else
            {
                array[i]=right[k];
                ++k;
            }
            ++i;
        }
        while(j<lim-l+1)
        {
            array[i]=left[j];
            ++j;
            ++i;
        }
        while(k<r-lim)
        {
            array[i]=right[k];
            ++k;
            ++i;
        }
    }
}
