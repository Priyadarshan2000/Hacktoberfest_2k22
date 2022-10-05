#include<stdio.h>
#include<stdlib.h>
void threeTuple(int **a, int m, int n, int count)
{
    int x = ((m*n)-count);

    int **b = (int**)malloc((x+1)*sizeof(int*));

    for(int i = 0; i < m; i++)
        b[i] = (int*)malloc(3*sizeof(int));

    b[0][0]= m;
	b[0][1]= n;
	b[0][2]= x;
	int k = 1;
	for(int i = 0; i < x+1; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(a[i][j]!=0)
			{
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
			}
		}
	}
	for(int i = 0; i < x+1; i++)
    {
        for(int j = 0; j < 3; j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
}
int main()
{
    int **a;  //for sparse matrix
    int n,m,count = 0;
    printf("Enter the array size: ");
    scanf("%d%d",&m,&n);
    a = (int**)malloc(m*sizeof(int*));

    for(int i = 0; i < m; i++)
        a[i] = (int*)malloc(n*sizeof(int));

    //taking the matrix input
    printf("Enter the matrix elements: ");
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                count++; //counts the number of zero elements
        }
    }

    if(count >((m * n) / 2))
    {
        printf("sparse matrix");
        threeTuple(a,m,n,count);
    }
    else
        printf("not sparse matrix");

    for(int i = 0; i < m; i++)
        free(a[i]);
    free(a);
}
