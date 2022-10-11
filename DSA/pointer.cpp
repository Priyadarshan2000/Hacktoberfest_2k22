#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int arr[n];
  unordered_map<int,int>mp;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    mp[arr[i]]++;
  }
  for(auto it:mp){
    cout<<it.first<<" "<<it.second<<endl;
  }
}