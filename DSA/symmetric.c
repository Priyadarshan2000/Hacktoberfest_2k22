#include<stdio.h>

int main()
{
   int arr[5][2];
   arr[0][0] = 1; arr[0][1] = 2;
   arr[1][0] = 3; arr[1][1] = 4;
   arr[2][0] = 5; arr[2][1] = 1;
   arr[3][0] = 4; arr[3][1] = 3;
   arr[4][0] = 1; arr[4][1] = 5;

   for(int i=0; i<5; i++){
      for(int j=i+1; j<5; j++){
         if(arr[i][0]==arr[j][1] && arr[i][1]==arr[j][0])
           printf("(%d, %d) ", arr[i][0], arr[i][1]);
      }
   }

   return 0;
}
