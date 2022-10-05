#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		
	}
 for ( i = 0, j = n - 1; i < n/2; i++, j--)  
	{
		swap(arr[i],arr[j]);
	}
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
	}
	
}
