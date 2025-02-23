#include<stdio.h>
#include<stdlib.h>
int a[50][50],n,visited[40];
int q[40],front=-1,rear=-1;
int s[40],top=-1;

void bfs(int);
void dfs(int);

int main()
{
int ch,start;
printf("Enter number of vertices:\n");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:");
for(int i=1;i<=n;i++)
{
  for(int j=1; j<=n; j++)
 {
  scanf("%d",&a[i][j]);
}
}
for (int i=1;i<=n;i++)
{
visited[i]=0;
}
printf("\nEnter the starting vertex:");
scanf("%d",&start);
printf("\n1.BFS==>Print all the nodes reachable from given straing node");
printf("\n2.DFS==>Print all the nodes reachable from given staring node");
printf("\n3.exit");
printf("\nEnter choice:");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("\nNodes reachable from given node are:");
bfs(start);

for(int i=1;i<=n;i++)
{
if(visited[i]==0)
{
  printf("\nNot reachable: %d",i);
}
}
break;

case 2: printf("\nNodes reachble are:");
   dfs(start);
  break;

case 3: exit(0);
default: printf("Enter valid choice");
}
}

void bfs(int v)
{
int cur,i;
visited[v]=1;
q[++rear]=v;
while(front!=rear)
{
cur=q[++front];
for(i=1;i<=n;i++)
{
if((a[cur][i]==1)&& (visited[i]==0))
{
visited[i]=1;
q[++rear]=i;
printf("%d",i);
}
}
}
}
void dfs(int v)
{
int i;
visited[v]=1;
s[++top]=v;
for(i=1;i<=n;i++)
{
if((a[v][i]==1)&&(visited[i]==0))
{
printf("%d",i);
dfs(i);
}
}
}
