#include<stdio.h>
#define max 10

int n,adj[max][max],visited[max];
void bfs();
void readmatrix();
int main()
{
int source;
printf("Enter the source node:");
scanf("%d",&source);
readmatrix();
bfs(source);
}
void readmatrix()
{
int i,j;
printf("Enter Number of nodes:");
scanf("%d",&n);
printf("Enter Adjacency matrix \n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
scanf("%d",&adj[i][j]);
for(i=1;i<=n;i++)
visited[i]=0;
}
void bfs(int source)
{
int queue[max];
int i,front,rear,root;
printf("The order is \n");
front=rear=0;
visited[source]=1;
queue[rear++]=source;
printf("%d",source);
while(front != rear)
{
root=queue[front];
for(i=1;i<=n;i++)
if(adj[root][i] && ! visited[i])
{
visited[i]=1;
queue[rear++]=i;
printf("-->%d",i);
}
front++;
}
}
