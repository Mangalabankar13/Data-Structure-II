#include<stdio.h>
int a,b,u,v,i,j,n,ne=1,mincost=0,min;
int cost[10][10],visited[10]={0};
void main()
{
 printf("\nenter no of vertex:");
 scanf("%d",&n);
 printf("\nenter cost matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&cost[i][j]);
   if(cost[i][j]==0)
   cost[i][j]=999;
  }
 }
 visited[1]=1;
 while(ne<n)
 {
  for(i=1,min=999;i<=n;i++)
   for(j=1;j<=n;j++)
    if(cost[i][j]<min && visited[i]!=0)
    {
     min=cost[i][j];
     a=u=i;
     b=v=j;
    }
    if(visited[u]==0||visited[v]==0)
    {
     printf("\nedge%d:(%d %d) cost:%d",ne++,a,b,min);
     mincost=mincost+min;
     visited[b]=1;
    } 
   cost[a][b]=cost[b][a]=999;
 }
 printf("\nminimum cost=%d",mincost);
}

        
 
