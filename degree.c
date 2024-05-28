#include<stdio.h>
void degree(int a[10][10],int n)
{
 printf("\n vertex  ind  out  total");
 int i,j;
 for(i=1;i<=n;i++)
 {
  int sumind=0,sumout=0;
  for(j=1;j<=n;j++)
  {
   sumind=sumind+a[j][i];
   sumout=sumout+a[i][j];
  }
  printf("\nv%d\t%d\t%d\t%d\t",i,sumind,sumout,sumind+sumout);
 }
}
void main()
{
 int a[10][10],i,j,n;
 printf("\nenter no.of vertex:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   a[i][j]=0;
   if(i!=j)
   {
    printf("\nenter edge between v%d & v%d:",i,j);
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
 degree(a,n);
} 

             
