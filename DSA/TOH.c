#include <stdio.h>  
int count=0;
void towerOfHanoi(int n, char source, char inter, char dest) 

{ 
	if (n == 1) 
	{ 
		printf("\n Move disk 1 from rod %c to rod %c", source, dest); 
		count++;
		return; 
	} 
	towerOfHanoi(n-1,source,dest,inter); 
towerOfHanoi(1,source,inter,dest);	 
	towerOfHanoi(n-1, inter, source, dest); 
} 

int main() 
{ 
	int n;
	printf("enter the no of disk");
	scanf("%d",&n);
	towerOfHanoi(n, 'A', 'B', 'C'); 
	printf("\nthe no of movement is %d ",count);
	return 0; 
} 

