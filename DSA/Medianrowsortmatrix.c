#include <stdio.h>

int main(){
    int mat[3][3] ={{1, 3, 5}, 
                    {2, 6, 9}, 
                    {3, 6, 9}};
    int arr[9], x=0;
    for(int i=0; i<3; i++){
       for(int j=0; j<3; j++){
           arr[x++] = mat[i][j];
       }
    }
    
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("Median of the given matrix is : %d", arr[4]);
}
