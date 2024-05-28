#include<stdio.h>
#include<stdlib.h>
#define max 50
struct stack
{
 int data[max];
 int top;
};
struct stack s;
void init()
{
 s.top=-1;
}
int isempty()
{
 return(s.top==-1);
}
int isfull()
{
 return(s.top==max-1);
}
void push(int val)
{
 s.data[++s.top]=val;
}
int pop()
{
 return(s.data[s.top--]);
}
void topology(int a[10][10],int n)
{
 int visited[10]={0},i,j,k;
 int ind[10]={0};
 init();
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   ind[i]=ind[i]+a[j][i];
  }
 }
 while(1)
 {
  for(i=1;i<=n;i++)
  {
   if(ind[i]==0 && visited[i]==0)
    push(i);
    visited[i]=1;
    printf("v%d\t",i);
  } 
  k=pop();
  for(j=1;j<=n;j++)
  {
   if(a[k][j]==1)
   ind[j]=ind[j]-1;
  }
  if(isempty())
  {
   break;
  }
 }
}
void main()
{
 int a[10][10],n,i,j;
 printf("no of vertex:");
 scanf("%d",&n);
 printf("\nenter matrix:");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 topology(a,n);
}

      
      
