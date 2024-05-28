#include<stdio.h>
void main()
{
 int a[10][10],i,j,n;
 printf("\nenter no.of vertices:");
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
}



     
