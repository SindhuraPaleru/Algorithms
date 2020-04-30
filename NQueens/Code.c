#include <stdio.h>
int x[4];
void main()
{
    nqueen(1,4);
}
void nqueen(int k,int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
                print(n);
            else
                nqueen(k+1,n);
        }
    }
}
int place(int row,int col)
{
    int i;
    for(i=1;i<row;i++)
    {
        if(x[i]==col||abs(row-i)==abs(col-x[i]))
            return 0;
    }
    return 1;
}
void print(int n)
{
    int i;
    printf("\nSolution vector is:");
    for(i=1;i<=n;i++)
        printf("%d\t",x[i]);
}
