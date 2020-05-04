#include<stdio.h>
int m,w[10],x[10];
void main()
{
    int s,k,r=0,n,i;
    printf("\nEnter number of elements:");
    scanf("%d",&n);
    printf("\nEnter sum:");
    scanf("%d",&m);
    printf("\nEnter elements:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        r+=w[i];
    }
    if(r<m||m<w[1])
    {
        printf("\nSubset is not possible");
        return;
    }
    sos(0,1,r);
}
void sos(int s,int k,int r)
{
    int i;
    x[k]=1;
    if(m==s+w[k])
    {
        printf("\nSubset is:");
        for(i=1;i<k;i++)
        if(x[i]==1)
            printf("\t%d",w[i]);
    }
    else if(s+w[k]+w[k+1]<=m)
    {
        sos(s+w[k],k+1,r-w[k]);
    }
    if(s+w[k+1]<=m&&s+r-w[k]>=m)
    {
        sos(s,k+1,r-w[k]);
    }
}
