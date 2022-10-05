/*Egg Dropping Puzzle

You are given N identical eggs and you have access to a K-floored building from 1 to K.
There exists a floor f where 0 <= f <= K such that
any egg dropped at a floor higher than f will break,
and any egg dropped at or below floor f will not break.
There are few rules given below. 
An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
Return the minimum number of moves that you need to determine with 
certainty what the value of f is. 
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int t[201][201];
    int solve(int n,int f){
        if(n==1) return f;
        if(f==1 || f==0) return f;
        
        if(t[n][f]!=-1) return t[n][f];
        
        int ans = INT_MAX;
        for(int i=1;i<=f;i++){
            int temp = 1+ max(solve(n-1,i-1),solve(n,f-i));
            ans = min(ans,temp);
        }
        return t[n][f] = ans;
    }
    int eggDrop(int n, int k) 
    {
        memset(t,-1,sizeof(t));
        return solve(n,k);
    }
};

int main()
{
    int t;
    cout<<"Enter the number of test cases : ";
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        Solution obj;
        cout<<obj.eggDrop(n, k)<<endl;
    }
    return 0;
}
