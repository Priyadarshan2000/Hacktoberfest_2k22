//You are given a number n
//you have to print all valid combinations that can be made using n pairs of brackets

#include<bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;
// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    //Helping recursive function to generate parenthesis	
    void ss(vector<string> &a,string s,int c,int o,int n) 
    {
        
        if(o==0 and c==0){
            a.push_back(s);
            return;
        }
       if(o>0){
           ss(a,s+"(",c,o-1,n);
       }
            
        if(o<c){
           // cout<<o<<" "<<c<<endl;
            ss(a,s+")",c-1,o,n);
        }

    }
    vector<string> AllParenthesis(int n) 
    {
            vector<string> a;
            ss(a,"",n,n,n);
             return a;
        //returning the vector containing permutations of braces 
    }
};




int main() 
{ 

	int n;
	cin>>n;
	Solution ob;
	vector<string> result = ob.AllParenthesis(n); 
	sort(result.begin(),result.end());
	for (int i = 0; i < result.size(); ++i)
		cout<<result[i]<<"\n";	
	return 0; 
} 
  
