#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int *arr, int size)
{
    for (int j = 0; j < size - 1; ++j)
    {

        int flag = 0;

        for (int i = 0; i < size - j - 1; ++i)
        {

            if (*(arr + i) > *(arr + i + 1))
            {

                int temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}
void display(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", *(arr + i));
    }
    printf("\n");
}
int main()
{
    int size, *arr, i;
    printf("Enter the no.of elements:\n");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    printf("Enter the elements of array:\n");
    for (i = 0; i < size; i++)
        scanf("%d", arr + i);
    printf("Elements before Sorting:\n\n");
    display(arr, size);
    bubbleSort(arr, size);
    printf("Elements after Sorting:\n\n");
    display(arr, size);
}