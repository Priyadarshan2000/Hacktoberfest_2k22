#include <stdio.h>

int main ()
{
    int num = 18, sum = 0;
    
    for(int i = 1; i < num; i++)
    {
        if(num % i == 0) 
            sum = sum + i; 
    }
if(sum > num){
 printf("%d is an Abundant Number\n",num);
 printf("Num: %d\nSum: %d\nAbundance: %d", num, sum, (sum-num)); 
} else
 printf("%d is not a Abundant Number",num); 
} 
