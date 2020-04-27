#include<stdio.h>
#define inf 999
int p[20],visited[20];
void read(int a[20][20],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
             printf("%d,%d:",i,j);
             scanf("%d",&a[i][j]);
        }
    }

}
void union_set(int u,int v,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(p[i]==v)
            p[i]=u;
    }
}
int find_rep(int i)
{
    return p[i];
}
int krushkal(int adj[20][20],int n)
{
    int nv=1,i,u,v,j,min,x,y,cost=0;
    for(i=0;i<n;i++)
        p[i]=i;
    while(nv<n)
    {
        min=inf;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(adj[i][j]!=0&&min>adj[i][j])
                {
                    min=adj[i][j];
                    x=i;
                    y=j;
                }
        u=find_rep(x);
        v=find_rep(y);
        if(u!=v)
        {
            union_set(u,v,n);
            printf("\n%d->%d",x,y);
            cost+=adj[x][y];
        }
         adj[x][y]=adj[y][x]=inf;
         nv++;
    }
    return cost;
}
void main()
{
    int n,adj[20][20];
    printf("\nEnter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter weighted matrix:");
    read(adj,n);
    printf("%d",krushkal(adj,n));
}
