#include<stdio.h>
#include<stdlib.h>

void countSort(int *arr, int n, int e){
    int *output, *count, max;

    max = arr[0];

    //finding the maximum number
    for(int i = 1; i < n; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }

    //dynamically creating the count and output array
    count = (int*)calloc(max,sizeof(int));
    output = (int*)calloc(n,sizeof(int));

    //initializing all the values to 0
    for(int i = 0; i <= max; i++)
        count[i] = 0;

    //finding the frequency of all the occurrences
    for(int i = 0; i < n; i++)
        count[(arr[i]/e)%10]++;

    //cumulative sum for duplicates
    for(int i = 1; i <= max; i++)
        count[i]+= count[i-1];

    //storing all the elements to output traversing from back
    for(int i = n - 1; i >= 0; i--){
        output[count[(arr[i]/e)%10] - 1] = arr[i];
        count[(arr[i]/e)%10]--;
    }

    //output to main array
    for(int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int *arr, int n){
    int max, i, e;
    max = arr[0];

    //finding the maximum number
    for(i = 1; i < n; i++)
    {
        if(max < arr[i])
            max = arr[i];
    }

    for(e = 1; max/e > 0; e *= 10)
        countSort(arr, n, e);
}

int main(void){
    int *arr, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int*)calloc(n,sizeof(int));
    printf("Enter %d elements int the array:\n", n);
    for(int i = 0; i < n; i++){
        printf("Enter %dth element: ",i+1);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    printf("The elements before sorting:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    radixSort(arr, n);
    printf("\n\nThe elements after sorting:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
    return 0;
}
