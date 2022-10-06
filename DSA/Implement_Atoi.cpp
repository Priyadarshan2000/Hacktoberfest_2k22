// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) 
    {
        //Your code here
        int c;
        try{
            
            c = stoi(str);
        }
        catch(...){
            return -1;
        }
        int g=0;
        if(c<0)
            g=1;
        long int n = abs(c);
        while(n)
        {
            ++g; 
            n /= 10;
        }
       // cout<<g<<endl<<str.length();
        if(g == str.length())
            return c;
        else
            return -1;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends