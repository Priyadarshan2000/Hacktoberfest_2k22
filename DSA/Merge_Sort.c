#include <stdio.h>
#include <stdlib.h>
void merge(int *a, int low, int mid, int high)
{

    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[low + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        int m = low + (high - low) / 2;

        mergeSort(a, low, m);
        mergeSort(a, m + 1, high);
        merge(a, low, m, high);
    }
}
int main()
{
    int n, *a, i;
    printf("Enter the no of elements:");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter elements in the array:");
    for (i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("Before Merge Sort the contents are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", *(a + i));
    mergeSort(a, 0, n - 1);
    printf("\nAfter Merge Sort the contents are:\n");
    for (i = 0; i < n; i++)
        printf("%d\t", *(a + i));
    return 0;
}