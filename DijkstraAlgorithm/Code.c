#include<stdio.h>
#define inf 999

void main()
{
    int min,cost[10][10],dist[10],nv,x,visited[10],i,j,n,vs;
    printf("\nEnter number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the weighted matrix:");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            printf("\na[%d][%d]:",i,j);
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=inf;
        }
    printf("\nEnter source vertex:");
    scanf("%d",&vs);
    for(i=0;i<n;i++)
    {
        visited[i]=0;
        dist[i]=cost[vs][i];
    }
    nv=1;
    visited[vs]=1;
    while(nv<n)
    {
        min=inf;
        for(i=0;i<n;i++)
           if(min>dist[i]&&visited[i]==0)
           {
               min=dist[i];
               x=i;
           }
        visited[x]=1;
        for(i=0;i<n;i++)
            if(dist[i]>cost[x][i]+dist[x]&&visited[i]==0)
                dist[i]=cost[x][i]+dist[x];
        nv++;
    }
    for(i=0;i<n;i++)
        if(vs!=i)
            printf("\n%d-->%d,cost=%d",vs,i,dist[i]);
}
