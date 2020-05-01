#include<stdio.h>
#define inf 999
void main()
{
    int i,j,min_wt,a[10][10],vs,n;
    printf("\nEnter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the weighted matrix:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("\na[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
    printf("\nEnter source vertex:");
    scanf("%d",&vs);
    min_wt=prims(a,n,vs);
    printf("\nminwt:%d",min_wt);
}
int prims(int a[10][10],int n,int vs)
{
    int i,j,x,y,min,tree[10][10],visited[10],cost=0,nv;
    for(i=0;i<n;i++)
        visited[i]=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            tree[i][j]=0;
    visited[vs]=1;
    nv=1;
    while(nv<n)
    {
        min=inf;
        for(i=0;i<n;i++)
            if(visited[i]==1)
                for(j=0;j<n;j++)
                    if(visited[j]==0&&a[i][j]!=0&&min>a[i][j])
                    {
                        min=a[i][j];
                        x=i;
                        y=j;
                    }
        nv++;
        cost+=min;
        tree[x][y]=min;
        visited[y]=1;
        printf("(v%d,v%d)->",x,y);
    }
    printf("\nThe spanning tree is(with weights) : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d\t",tree[i][j]);
        printf("\n");
    }
    return cost;
}
