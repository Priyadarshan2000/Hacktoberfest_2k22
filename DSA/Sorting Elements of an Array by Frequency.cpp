#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool static comp(pair<int ,int> a,pair<int ,int> b){
        if(a.first>b.first)
            return true;
        else if(a.first==b.first and a.second<b.second)
            return true;
        return false;
    }

    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n)
    {
        map< int , int > mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]+=1;
        vector<pair< int,int > > p;
        for(auto i :mp){
            pair<int,int> a;
            a.first=i.second;
            a.second=i.first;
            p.push_back(a);
        }
        vector<int> aa;
        sort(p.begin(),p.end(),comp);
        for(int i=0;i<p.size();i++){
            while(p[i].first--)
                aa.push_back(p[i].second);
        }
        return aa;
    }
};



int main() {
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	
	
	return 0;
}

  
