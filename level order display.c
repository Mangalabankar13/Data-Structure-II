#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct node
{
 int data;
 struct node *left,*right;
}NODE;
struct queue
{
 struct node *data1[max];
 int front,rear;
};
struct queue q;
void initq()
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
void add(NODE *num)
{
 q.data1[++q.rear]=num;
}
NODE *delq()
{
 return q.data1[++q.front];
}
NODE *create(NODE *root)
{
NODE *newnode,*temp,*parent;
 int i,n;
 printf("enter limit:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  newnode=(NODE *)malloc(sizeof(NODE));
  printf("\nenter value:");
  scanf("%d",&newnode->data);
  newnode->left=NULL;
  newnode->right=NULL;
  if(root==NULL)
  {
   root=newnode;
   continue;
  }
  temp=root;
  while(temp!=NULL)
  {
   parent=temp;
   if(newnode->data<=temp->data)
    temp=temp->left;
   else
    temp=temp->right;
  }
  if(newnode->data<=parent->data)
   parent->left=newnode;
  else
   parent->right=newnode;
 }
 return root;
}
void level_disp(NODE *root)
{
 NODE *temp,*m=NULL;
 int level=0,node=0;
 static int c=0;
 initq();
 add(root);
 add(m);
 printf("\nlevel_%d=>",level);
 while(!isempty())
 {
  temp=delq();
  if(temp==m)
  {
   printf("\ntotal node at %d level=%d",level,node);
   node=0;
   level++;
   if(!isempty())
   {
    add(m);
    printf("\nlevel_%d=>",level);
   }
   c++; 
  }
  else
  {
   printf("%d\t",temp->data);
   node++;
   if(temp->left!=NULL)
   add(temp->left);
   if(temp->right!=NULL)
   add(temp->right);
  }
 }
 printf("\ntotal level=%d",c);
}
void main()
{
 NODE *root=NULL;
 root=create(root);
 level_disp(root);
}



                  
