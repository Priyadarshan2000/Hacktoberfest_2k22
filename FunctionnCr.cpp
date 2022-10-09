#include<bits/stdc++.h>
using namespace std;

/* nCr = n! / (r!*(n-r)!) */

// Making factorial formula function
int factorial(int n){
    int fact = 1;

    for(int i=1 ; i<= n ; i++){
        fact = fact * i;
    }
    return fact;
}

// Making nCr formula function
int nCr(int n,int r){
    
    int num = factorial(n);
    int denom = factorial(r)*factorial(n-r);

    return num/denom;
}

int main()
{
    int n,r;
    cout<<"Enter the values of n and r : "<<endl;
    cin>> n >> r;

    cout<<"Answer is : "<< nCr(n,r) <<endl;

return 0;
}