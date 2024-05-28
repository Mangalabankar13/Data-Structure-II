#include<stdio.h>
#include<stdlib.h>
#define max 10
struct queue
{
 int data1[max];
 int rear,front;
};
struct queue q;
void init()
{
 q.front=q.rear=-1;
}
int isempty()
{
 return(q.front==q.rear);
}
int isfull()
{
 return(q.rear==max-1);
}
void add(int v)
{
 q.data1[++q.rear]=v;
}
int removeq()
{
 return(q.data1[++q.front]);
}
void bfs(int a[10][10],int n)
{
 int visited[10]={0},i,j;
 init();
 i=1;
 add(i);
 visited[i]=1;
 while(!isempty())
 {
  i=removeq();
  printf("v%d\t",i);
  for(j=1;j<=n;j++)
  {
   if((a[i][j]==1) && (visited[j]==0))
   {
    add(j);
    visited[j]=1;
   }
  }
 }
}
void main()
{
 int a[10][10],n,i,j;
 printf("\nenter no of vertex:");
 scanf("%d",&n);
 printf("\nenter matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 bfs(a,n);
}


            
