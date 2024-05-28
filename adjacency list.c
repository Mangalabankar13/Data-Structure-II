#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *next;
}NODE;
NODE *head[10];
void adjacencylist(int a[10][10],int n)
{
 int i,j;
 NODE *temp,*newnode;
 for(i=1;i<=n;i++)
 {
  head[i]=NULL;
  for(j=1;j<=n;j++)
  {
   if(a[i][j]==1)
   {
    newnode=(NODE *)malloc(sizeof(NODE));
    newnode->data=j;
    newnode->next=NULL;
    if(head[i]==NULL)
    {
     head[i]=temp=newnode;
    }
    else
    {
     temp->next=newnode;
     temp=newnode;
    }
   }
  }
 }
}
void displist(int n)
{
 int i;
 NODE *temp;
 printf("\nadjacency list:\n");
 for(i=1;i<=n;i++)
 {
  printf("\nv%d->",i);
  for(temp=head[i];temp!=NULL;temp=temp->next)
  {
   printf("v%d->",temp->data);
  }
  printf("NULL");
 }
}
void main()
{
 int a[10][10],n,i,j;
 printf("\nenter no.of vertex:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   a[i][j]=0;
   if(i!=j)
   {
    printf("\nenter edges between v%d & v%d:",i,j);
    scanf("%d",&a[i][j]);
   }
  }
 }
 printf("\nadjacency matrix:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   printf("%d\t",a[i][j]);
  }
  printf("\n");
 }
 adjacencylist(a,n);
 displist(n);
}

       
    
