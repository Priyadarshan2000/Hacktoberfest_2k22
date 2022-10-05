/*The Celebrity Problem 

A celebrity is a person who is known to all but does not know anyone at a party.
If you go to a party of N people, find if there is a celebrity in the party or not.
A square NxN matrix M[][] is used to represent people
at the party such that if an element of row i and column j  is set to 1
it means ith person knows jth person. Here M[i][i] will always be 0.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    { 
        stack<int> S;
        for(int i=0;i<n;i++){
            S.push(i);
        }
        
        while(S.size() >= 2){
            int i = S.top();
            S.pop();
            int j = S.top();
            S.pop();
            
            if(M[i][j] == 1){
                //if i knows j, then i is not a celeb
                S.push(j);
            }
            else{
                S.push(i);
            }
        }
        
        int celeb = S.top();
        S.pop();
        for(int i=0;i<n;i++){
            if(i!=celeb){
                if(M[i][celeb] == 0 || M[celeb][i] == 1){
                    return -1;
                }
            }
        }
        return celeb;
    }
};

int main()
{
    int t;
    cout<<"Enter the number of test cases : ";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"Enter the size of the vector : ";
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution obj;
        cout<<obj.celebrity(M,n)<<endl;
    }
}
