#include<stdio.h>    
#include<stdlib.h>  
int main(){  
int a[10][10],b[10][10],mul[10][10],r,c,m,n,i,j,k;    
  
printf("enter the number of row of 1st matrix=");    
scanf("%d",&r);    
printf("enter the number of column of 1st matrix=");    
scanf("%d",&c); 
printf("enter the number of row of 2nd matrix=");    
scanf("%d",&m);    
printf("enter the number of column of 2nd matrix=");    
scanf("%d",&n);    

if(c!=m)
{
	printf("Not possible!");
}   
else
{
printf("enter the first matrix element=\n");    
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{    
scanf("%d",&a[i][j]);    
}    
}
printf("1st matrix is:\n"); 
for (i = 0; i < r; i++) {
for (j = 0 ; j < c; j++) 
{ 
printf("%d\t", a[i][j]);
}
printf("\n");
}    
printf("enter the second matrix element=\n");    
for(i=0;i<m;i++)    
{    
for(j=0;j<n;j++)    
{    
scanf("%d",&b[i][j]);    
}    
}
printf("2nd matrix is:\n");
for (i = 0; i < m; i++) {
for (j = 0 ; j < n; j++) 
{ 
printf("%d\t", b[i][j]);
}
printf("\n");
}    
printf("multiplication of the matrix result=\n");    
for(i=0;i<r;i++)    
{    
for(j=0;j<n;j++)    
{    
mul[i][j]=0;    
for(k=0;k<c;k++)    
{    
mul[i][j]+=a[i][k]*b[k][j];    
}    
}    
}
//for printing result    
for(i=0;i<r;i++)    
{    
for(j=0;j<c;j++)    
{    
printf("%d\t",mul[i][j]);    
}    
printf("\n");    
} 
}
return 0;  
}  
