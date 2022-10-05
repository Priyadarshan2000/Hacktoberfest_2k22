#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n, *arr, i, j, tmp, count;
    printf("\n\nEnter the no.of elements for the array:-\n");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("\nEnter the array elements:-\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n - 1; i++)
    {
        count = 0;
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                count++;
            }
        }
        if (count == 0)
            break;
    }
    printf("\nThe sorted array is:-\n");
    for (i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    return 0;
}