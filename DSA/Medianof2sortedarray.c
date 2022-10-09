#include <stdio.h>

int getMedian(int ar1[], int ar2[], int n)
{
    int j = 0;
    int i = n - 1;
    while (ar1[i] > ar2[j] && j < n && i > -1)
      {
            int temp = ar1[i];
            ar1[i] = ar2[j];
            ar2[j] = temp;
            i--;
            j++;
      }


    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){ if(ar1[i]>ar1[j]){
                int temp = ar1[i];
                ar1[i] = ar1[j];
                ar1[j] = temp;
            }
        }
    }
    

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){ if(ar2[i]>ar2[j]){
                int temp = ar2[i];
                ar2[i] = ar2[j];
                ar2[j] = temp;
            }
        }
    }

    return (ar1[n - 1] + ar2[0]) / 2;
}

int main()
{
 
   int arr1[]={1, 11, 15, 26, 39}, arr2[]={2, 12, 17, 30, 45};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   
   printf("%d",getMedian(arr1, arr2, n));

   return 0;
}
