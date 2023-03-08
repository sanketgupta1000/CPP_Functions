void mergesort(int *, int);
void merge(int *, int);
void copyintarr(int *, int *, int);

void mergesort(int *a, int n)
{
    if(n>1)
    {
        mergesort(a, (n/2));
        mergesort(a+(n/2), (n-(n/2)));
        merge(a, n);
    }
}

void merge(int *a, int n)
{
    int *b=a+(n/2);
    int size1=(n/2), size2=(n-(n/2));
    int i1, i2, it;
    int temp[n];
    for(i1=0, i2=0, it=0; ((i1<size1)&&(i2<size2)); it++)
    {
        if(a[i1]<=b[i2])
        {
            temp[it]=a[i1++];
        }
        else
        {
            temp[it]=b[i2++];
        }
    }
    if(i1==size1)
    {
        copyintarr(temp+it, b+i2, size2-i2);
    }
    else
    {
        copyintarr(temp+it, a+i1, size1-i1);
    }
    copyintarr(a, temp, n);
}

void copyintarr(int *dest, int *src, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        *(dest+i)=*(src+i);
    }
}