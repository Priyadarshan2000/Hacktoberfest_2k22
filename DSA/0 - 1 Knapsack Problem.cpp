/*0 - 1 Knapsack Problem 

You are given weights and values of N items, put these items in a knapsack 
of capacity W to get the maximum total value in the knapsack. 
Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] 
which represent values and weights associated with N items respectively.
Also given an integer W which represents knapsack capacity, 
find out the maximum value subset of val[] such that 
sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item or don’t pick it (0-1 property)*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    {
        int t[n+1][W+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<W+1;j++){
                if(i==0 || j==0)
                    t[i][j] = 0;
                    
                else if(wt[i-1] <= j)
                    t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
                    
                else if(wt[i-1] > j)
                     t[i][j] = t[i-1][j];
            }
        }  
    	return t[n][W];
	}
}
    
int main()
{
    int t;
    cout<<"Enter the number of test cases : ";
    cin>>t;
    while(t--)
    {
        int n, w;
        cout<<"Enter the arrays' size : ";
        cout<<"Enter the size of the knapsack : ";
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        for(int i=0;i<n;i++)
            cin>>val[i];
            
        for(int i=0;i<n;i++)
            cin>>wt[i];
            
        Solution obj;
        cout<<obj.knapSack(w, wt, val, n)<<endl;  
    }
	return 0;
}
