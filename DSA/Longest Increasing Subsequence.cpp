/*Longest Increasing Subsequence
Given an array of integers, find the length of 
the longest (strictly) increasing subsequence from the given arra*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int longestSubsequence(int n, int arr[])
    {
       int list[n];
       
       list[0] = 1;
       
       for(int i=1;i<n;i++){
           
           list[i] = 1;
           
           for(int j=0;j<i;j++){
               
               if(arr[i] > arr[j] and list[i] <= list[j])
               
                  list[i] = list[j] + 1;
           }
       }
       
       return *max_element(list, list+n);
    }
};

int main()
{
    int t,n;
    cout<<"Enter the number of testcases : ";
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution obj;
        cout << obj.longestSubsequence(n, arr) << endl;
    }
}
