#include<stdio.h>
int partition(int arr[], int start, int end){
    int i, j;
    int pivot= arr[end];
     i=start-1;
     for(j=start; j<end; j++){
         if(arr[j]<pivot){
             i++;
             int t= arr[i];
             arr[i]=arr[j];
             arr[j]=t;
         }
         

     }
     int t= arr[i+1];
     arr[i+1]= arr[j];
     arr[j]=t;
     return(i+1);


}
void quicksort(int arr[], int start, int end){
    if (start<end){
        int p=partition(arr, start, end);
        quicksort(arr, start, p-1);
        quicksort(arr, p+1, end);
    }
}
void printarray(int arr[], int n){
    int i;
    for(i=0; i<n; i++){
        printf("%d\t", arr[i]);
    }
}
int main()
{
	int arr[10],n,i;
	printf("Enter the array size: ");
	scanf("%d",&n);
	printf("Enter the array elements:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\nBefore sorting array elements are:\t");
	printarray(arr,n);
	quicksort(arr,0,n-1);
	printf("\nAfter sorting array elements are:\t");
	printarray(arr,n);
	return 0;
}
