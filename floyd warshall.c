#include<stdio.h>
void floyd(int a[10][10],int n)
{
 int i,k,j;
 for(k=1;k<=n;k++)
 {
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(a[i][k]+a[k][j]<a[i][j])
    a[i][j]=a[i][k]+a[k][j];
   }
  }
 }
 printf("\noutput:\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   printf("%d\t",a[i][j]);
  }
  printf("\n");
 }
}
void main()
{
 int a[10][10],i,j,n;
 printf("\nenter vertex:");
 scanf("%d",&n);
 printf("\nenter matrix:");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 floyd(a,n);
}



         
