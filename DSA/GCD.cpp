#include <bits/stdc++.h>
using namespace std;
 
int static dp[1001][1001];
 

int gcd(int a, int b)
{
  
    if (a == 0)
        return b;
    if (b == 0)
        return a;
 
    
    if (a == b)
        return a;
     
  
    if(dp[a][b] != -1)
        return dp[a][b];
 
   
    if (a > b)
        dp[a][b] = gcd(a-b, b);
     
   
    else
        dp[a][b] = gcd(a, b-a);
     
   
    return dp[a][b];
}
