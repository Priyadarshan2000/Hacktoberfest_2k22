
#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    for(int i=0;i<matrix.size();i++){
       for(int j=i;j<matrix.size();j++){
           int t=matrix[i][j];
           matrix[i][j]=matrix[j][i];
           matrix[j][i]=t;
       } 
    }
    reverse(matrix.begin(),matrix.end());
}


// { Driver Code Starts.

int main()
{
  
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    
    return 0;
}
