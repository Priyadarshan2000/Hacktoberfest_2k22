#include <stdio.h>
#include <stdlib.h>
void CountingSort(int *array, int size)
{
    int i, *output, *count, max;
    max = *array;
    for (int i = 1; i < size; i++)
    {
        if (*(array + i) > max)
            max = *(array + i);
    }
    count = (int *)malloc(max * sizeof(int));
    output = (int *)malloc(size * sizeof(int));
    for (i = 0; i <= max; ++i)
    {
        *(count + i) = 0;
    }
    for (i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
    for (i = 1; i <= max; i++)
    {
        *(count + i) += *(count + i - 1);
    }
    for (i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (i = 0; i < size; i++)
    {
        *(array + i) = *(output + i);
    }
}
void display(int *array, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d  ", *(array + i));
    }
    printf("\n\n");
}
int main(void)
{
    int n, *array, i;
    printf("\n\nEnter the no.of elements:-\n\n");
    scanf("%d", &n);
    array = (int *)malloc(n * sizeof(int));
    printf("Enter the elements:-\n\n");
    for (i = 0; i < n; i++)
        scanf("%d", array + i);
    CountingSort(array, n);
    printf("Sorted elements are:-\n\n");
    display(array, n);
}