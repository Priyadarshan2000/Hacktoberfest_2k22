#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution
{
    public:
    vector<string> possibleWords(int a[], int N)
    {
         unordered_map<int, vector<string>>M;
        
        M[2] = {"a", "b", "c"};  
        M[3] = {"d", "e", "f"};   
        M[4] = {"g", "h", "i"};   
        M[5] = {"j", "k", "l"};       
        M[6] = {"m", "n", "o"};
        M[7] = {"p", "q", "r", "s"};
        M[8] = {"t", "u", "v"};
        M[9] = {"w", "x", "y", "z"};
        
        vector<string> first = M[a[0]];
        
        for(int i=1; i<N; i++)
        {
            
            vector<string> second = M[a[i]], ans;
            
            for(auto f:first)
            {
                for(auto s:second)
                    ans.push_back(f+s);
            }
            
            first = ans;
        }
        return first;
    }
};

int main() {
  
	int T;
	
	cin >> T; 
	
	while(T--){ 
	   int N;
	    
	   cin >> N;
	   
	   int a[N]; 
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; 
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  
