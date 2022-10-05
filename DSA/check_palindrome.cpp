#include <bits/stdc++.h>
using namespace std;
class Solution{

    public:

    bool check(vector<ll> A, vector<ll> B, int N) {

        sort(A.begin(), A.end());

        sort(B.begin(), B.end());

        for ( int i = 0; i < N; i ++){

            if (A[i] != B[i]) return false;

        }

        return true;

    }

};
//Driver code 
int main()
{
  int t;
  cin>>t;
  while(t--){
    string str;
    cin>>str;
    Solution ob;
    int ans = ob.minchar(str);
    cout<<and<<endl;
    }
    return 0;
    }
