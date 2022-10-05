#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *a, int n, int i)
{
    int max, left, right;
    max = i;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < n && a[left] > a[max])
        max = left;
    if (right < n && a[right] > a[max])
        max = right;
    if (max != i)
    {
        swap(&a[i], &a[max]);
        heapify(a, n, max);
    }
}

void heapsort(int *a, int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }
    for (i = n - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void display(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int main()
{
    int n, *a, i;
    printf("\nEnter the size of the array : \n");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter the elemets :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\nOriginal array : \n");
    display(a, n);
    heapsort(a, n);
    printf("\nsorted array: \n");
    display(a, n);
    return (0);
}
