// 04 Coin Change Problem

/* Given a value N, find the number of ways to make change for N cents, 
if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins.*/



#include<bits/stdc++.h>
using namespace std;


long long int count( int S[], int m, int n ){
        long long int t[m+1][n+1];
	for(long long int i=0;i<=m;i++)
		t[i][0]=1;
	for(long long int i=0;i<=n;i++)
		t[0][i]=0;	
	for(long long int i=1;i<=m;i++){
		for(long long int j=1;j<=n;j++){
			if(j < S[i-1])
				t[i][j] = t[i-1][j];
			else{
				t[i][j] = t[i-1][j] + t[i][j-S[i-1]];
			}
		}
	}
	return t[m][n];
}


int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
		cout<<count(arr,m,n)<<endl;
	}   
    return 0;
}
