//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int R, int C, vector<vector<int>>&a)  {
        // code here
        int i=0;
        int c=0,r=0;
        vector<int> aa;
        while(c<C and r<R){
            if(!(c<C and r<R)) break;
            for(i=c;i<C;i++) aa.emplace_back(a[r][i]);
            r++;
            if(!(c<C and r<R)) break;
            for(i=r;i<R;i++) aa.emplace_back(a[i][C-1]);
            C--;
            if(!(c<C and r<R)) break;
            for(i=C-1;i>=c;i--) aa.emplace_back(a[R-1][i]);
            R--;
            if(!(c<C and r<R)) break;
            for(i=R-1;i>=r;i--) aa.emplace_back(a[i][c]);
            c++;
        }
        reverse(aa.begin(),aa.end());
        return aa;
    }
};

//{ Driver Code Starts.
int main() {
   
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    
    	return 0;
}

// } Driver Code Ends
