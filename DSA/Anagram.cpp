#include<bits/stdc++.h>
using namespace std;

class Solution{
bool isAnagram(string a, string b){

        

        // Your code here

        unordered_map<char,int> mp;

        

        for(int i=0;i<a.length();i++){

            mp[a[i]]++;

        }

        

        for(int i=0;i<b.length();i++){

            

            if(mp[b[i]] != 0){

                mp[b[i]]--;

            }

            else{

                return 0;

            }

        }

        return 1; 

    }
    };
    
    //driver code
    int main(){
    int t;
    cin>>t;
    while(t--){
      string c,d;
      cin>>c>>d;
      solution obj;
      if(obj.isAngram(c,d)) cout << "YES" <<endl;
      else cout << "NO" << endl;
      }
      }
  
