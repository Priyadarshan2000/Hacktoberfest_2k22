#include<stdio.h>  
int main()
{
   
    char str[100] = "Rak))timb(ar", str_no_spc[100];
    int i=0, j=0 ;
    
  
    while(str[i] != '\0')
    {
        if(str[i] != '(' &&  str[i] != ')')//Excluding brackets.
        {
            str_no_spc[j++] = str[i];
        }
        i++;
    }
    str_no_spc[j] = '\0';
    
    
    printf("The string after removing all the spaces is:\n%s", str_no_spc);
    return 0;
}
