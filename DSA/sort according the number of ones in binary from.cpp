#include<bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> a,pair<int,int> b){
	if(a.first<b.first) return true;
	else if(a.first==b.first and a.second<=b.second) return true;
	return false;
}
void creampie(vector<int> &a,int n){
	int max=a[0];
	for(int i=0;i<n;i++){
		if(max<a[i]) max=a[i];
	}
	vector<int> t(max+1,0);
	for(int i=1;i<max+1;i++)
		t[i]=t[i/2]+i%2;
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++) v.push_back({t[a[i]],a[i]});
	//(v.begin(),v.end());
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<v.size();i++) cout<<v[i].second<<" ";
}
int main(void){
	
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	creampie(a,n);
}
