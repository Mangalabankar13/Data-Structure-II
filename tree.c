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
 NODE *temp,*parent,*newnode;
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
NODE *insert(NODE *root,int num)
{
 NODE *temp,*parent,*newnode;
 newnode=(NODE *)malloc(sizeof(NODE));
 newnode->data=num;
 newnode->left=NULL;
 newnode->right=NULL;
 if(root==NULL)
 {
  return newnode;
 }
 temp=root;
 while(temp!=NULL)
 {
  parent=temp;
  if(num<=temp->data)
   temp=temp->left;
  else
   temp=temp->right;
 }
 if(num<=parent->data)
  parent->left=newnode;
 else
  parent->right=newnode;
 return root;      
} 
void inorder(NODE *root)
{
 NODE *temp=root;
 if(temp!=NULL)
 {
  inorder(temp->left);
  printf("%d\t",temp->data);
  inorder(temp->right);
 }
}      
void preorder(NODE *root)
{
 NODE *temp=root;
 if(temp!=NULL)
 {
  printf("%d\t",temp->data);
  preorder(temp->left);
  preorder(temp->right);
 }
}
void postorder(NODE *root)
{
 NODE *temp=root;
 if(temp!=NULL)
 {
  postorder(temp->left);
  postorder(temp->right);
  printf("%d\t",temp->data);
 }
}
void main()
{
 int ch,num;
 NODE *root=NULL;
 do
 {
  printf("\n1.create \n2.insert \n3.inorder \n4.preorder \n5.postorder");
  printf("\nenter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:root=create(root);
          break;
   case 2:printf("\nenter value to insert:");
          scanf("%d",&num);
          root=insert(root,num);
          break;       
   case 3:printf("inorder=");
          inorder(root);
          break;
   case 4:printf("preorder=");
          preorder(root);
          break;
   case 5:printf("postorder=");
          postorder(root);
          break;
  }
 }while(ch<6);
}             


                  
