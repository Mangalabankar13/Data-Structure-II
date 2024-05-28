#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
 int data;
 struct node *left,*right;
}NODE;
NODE *create(NODE *root)
{
 int i,n;
 NODE *temp,*newnode,*parent;
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
   if(newnode->data<temp->data)
    temp=temp->left;
   else
    temp=temp->right;
  }
  if(newnode->data<parent->data)
   parent->left=newnode;
  else
   parent->right=newnode;
 }
 return root;
}
int countnode(NODE *root)
{
 static int c=0;
 NODE *temp=root;
 if(temp!=NULL)
 {
  c++;
  countnode(temp->left);
  countnode(temp->right);
 }
 return c;
}
int countleaf(NODE *root)
{
 static int c=0;
 NODE *temp=root;
 if(temp!=NULL)
 {
  if((temp->left==NULL)&&(temp->right==NULL))
  {
   c++;
  }
  countleaf(temp->left);
  countleaf(temp->right);
 }
 return c; 
}
void main()
{
 int ans,ans1;
 NODE *root=NULL;
 root=create(root);
 ans=countnode(root);
 printf("\ntotal nodes=%d",ans);
 ans1=countleaf(root);
 printf("\ntotal leaf nodes=%d",ans1);
} 

 
                               
