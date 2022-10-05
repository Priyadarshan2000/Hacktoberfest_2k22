#include<stdio.h> 
int main()
{
    //Initializing variables.
    char str1[100]="prep",str2[100]="perp";
    int first[26]={0}, second[26]={0}, c=0, flag=0;
    
    while(str1[c] != '\0')
    {
        first[str1[c]-'a']++;
        c++;
    }
     
    c=0;
   
    while(str2[c] != '\0')
    {
        second[str2[c]-'a']++;
        c++;
    }
   
    for(c=0;c<26;c++)
    {
        if(first[c] != second[c])
            flag=1;
    }
  
    if(flag == 0)
    {
        printf("\n%s and %s are Anagram Strings.",str1,str2);
    }
    else
    {
        printf("\n%s and %s are not Anagram Strings.",str1,str2);
    }
    return 0;
  
}
