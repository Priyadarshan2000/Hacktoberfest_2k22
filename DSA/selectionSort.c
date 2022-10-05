#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int *arr, int m)
{
    int min_index;
    for(int i = 0; i < m-1; i++)
    {
        min_index = i;
        for(int j = i+1; j < m; j++)
        {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        if(i != min_index)
            swap(&arr[i],&arr[min_index]);
    }
    printing(arr,m);
}
void printing(int *arr, int m)
{
    for(int i = 0; i < m; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void input(int *arr, int m)
{
    for(int i = 0; i < m; i++)
    {
        scanf("%d",&arr[i]);
    }
}
int main()
{
    int m;
    printf("Enter the size of the array: ");
    scanf("%d",&m);
    int *arr = (int *)calloc(m,sizeof(int));
    printf("Enter the array elements:\n");
    input(arr,m);
    printf("The array before sorting:\n");
    printing(arr,m);
    printf("Array after sorting:\n");
    selectionSort(arr, m);
    free(arr);
    return 0;
}
