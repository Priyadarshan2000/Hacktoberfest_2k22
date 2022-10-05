#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, *arr, i, j, k;
    printf("\n\nEnter the no.of elements for the array:-\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("\nEnter the array elements:-\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 1; i < n; i++)
    {
        k = arr[i];
        for (j = i - 1; j >= 0 && k < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = k;
    }
    printf("\nThe sorted array is:-\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}