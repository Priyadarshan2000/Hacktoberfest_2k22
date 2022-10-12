#include<stdio.h>
#include<math.h>

void convert(int octal)
{
    int i = 0, decimal = 0;
    
    //converting octal to decimal
    while (octal!=0)
    {
        int digit = octal % 10;
        decimal += digit * pow(8, i);

        octal /= 10;
        i++;
    }
    
    printf("Decimal Value: %d\n",decimal);
    
    long long binary = 0;
    int rem;
    i = 1;
    
    
    while(decimal!=0)
    {
        rem = decimal % 2;
        decimal /= 2;
        binary += rem * i;
        
        
        i *= 10;
    }
    
    printf("Binary Value: %d",binary);
}
 
int main()
{
    int octal;
    
    printf("Octal Value: "); 
    scanf("%d", &octal);
 
    convert(octal);
 
    return 0;
}
