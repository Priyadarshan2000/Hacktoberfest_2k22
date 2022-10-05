#include <stdio.h>
#include <stdlib.h>
void swap(int *arr, int *a)
{
    int t;
    t = *arr;
    *arr = *a;
    *a = t;
}
int part(int *arr, int low, int high)
{
    int j, pivot, i, t;
    j = low;
    pivot = *(arr + low);
    for (i = low + 1; i <= high; i++)
    {
        if (pivot > *(arr + i))
        {
            j++;
            swap((arr + i), (arr + j));
        }
    }
    swap((arr + low), (arr + j));
    return j;
}
void quicksort(int *arr, int low, int high)
{
    int j;
    if (high > low)
    {
        j = part(arr, low, high);
        quicksort(arr, low, j - 1);
        quicksort(arr, j + 1, high);
    }
}
void display(int *arr, int n)
{
    int i;
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", *(arr + i));
}
int main(void)
{
    int n, *arr, i;
    printf("Enter the no.of elements:\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
    quicksort(arr, 0, n - 1);
    display(arr, n);
}