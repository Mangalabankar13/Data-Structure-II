#include<stdio.h>
int ht[10];
void init()
{
 int i;
 for(i=0;i<10;i++)
 {
  ht[i]=-1;
 }
}  
int hash(int num,int i)
{
 return(num%10+i)%10;
}
void insert(int num)
{
 int i,index;
 for(i=0;i<10;i++)
 {
  index=hash(num,i);
  if(ht[index]==-1)
  {
   ht[index]=num;
   break;
  }
 }
}
void disp()
{
 int i;
 for(i=0;i<10;i++)
 {
  printf("%d\t",ht[i]);
 }
}
int search(int num)
{
 int i,index;
 for(i=0;i<10;i++)
 {
  index=hash(num,i);
  if(ht[index]==num)
  {
   return index;
  }
 }
 return -1;
}
void delete(int num)
{
 int index;
 index=search(num);
 if(ht[index]==-1)
  printf("\nno not found");
 else
 {
  ht[index]=-1;
  printf("\ndelete successfully");
 }
}
void main()
{
 int ch,num,index;
 init();
 do
 {
  printf("\n1.insert \n2.display \n3.search \n4.delete");
  printf("\nenter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nenter number:");
          scanf("%d",&num);
          insert(num);
          break;
   case 2:disp();
          break;          
   case 3:printf("\nenter no. to search:");
          scanf("%d",&num);
          index=search(num);
          if(index==-1)
           printf("\nno. not found:");
          else
           printf("\nno. found at position=%d",index);
           break;
   case 4:printf("\nenter no:");
          scanf("%d",&num);
          delete(num);
          break;
  }
 }while(ch<5);
} 

         
