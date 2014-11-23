void rewrite(int *m, int *n, int *mn, int size)
{
    for(int i=0; i<size; ++i,++mn,++m)
    {
        *mn=*m;// то же самое что и arrayMN[i]=arrayM[i];
    }
    for(int i=size; i<2*size; ++i,++mn, ++n)
    {
        *mn=*n;//то же самое что и arrayMN[i]=arrayN[j]; при том j=0;
    }
}
void sorting(int array[],  int size)//т.к функцию передается не сам массив а указатель но нулевой элемент нам не обязательно возвращать массив
{
    int i=0;
    int j=size;
    int p=array[size/2];
    int temp;

    while(i<=j)
    {
        while(array[i]<p) i++;
        while(array[j]>p) j--;
        if(i<=j)
        {
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
            i++;
            j--;
        }
    }
    if(j>0) sorting(array, j);
    if(i<size) sorting(array+i,size-i);//array+i это указатель на нулевой элемент нового подмассива
}
