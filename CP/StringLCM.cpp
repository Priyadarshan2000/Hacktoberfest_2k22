#include<bits/stdc++.h>

using namespace std;

// void solve(){

// 	string s1,s2;

// 	cin>>s1>>s2;
// 	string r = s1+s2;

// 	int l1 = s1.length();
// 	int l2 = s2.length();
// 	int isSame = 1;
// 	for(int i=0;i<l1+l2-1;i++){
// 		if(r[i] != r[i+1]){
// 			isSame = 0;
// 			break;
// 		}

// 	}
// 	int lindex = -1;

// 	if(l1 < l2){
// 		string temp = s2;
// 		s2 = s1;
// 		s1 = temp;

// 		swap(l1,l2);
// 	}
// 	int flag = 1;
// 	for(int i =0;i<=l1-l2;i+=l2){
// 		string r = s1.substr(i,l2);
// 		if(s2!=r){
// 			flag =0;
// 			break;
// 		}

// 		lindex = i;
// 	}
// 	lindex += l2-1;
	
// 	if(flag){
// 	 	string r = s1.substr(l1-l2,l2);
// 	 	if(r==s2){
// 	 		if(l1%l2 ==0){
// 	 			cout<<s1<<"\n";
// 	 		}else if(l1-l2 == lindex && isSame){
// 	 			s1 ="";
// 	 			for(int i =0;i<l1*l2;i++){
// 	 				s1.push_back(s2[0]);
// 	 			}

// 	 			cout<<s1<<"\n";
// 	 		}else{
// 	 			cout<<"-1\n";
// 	 		}
// 	 	}else{
// 	 		cout<<"-1\n";
// 	 	}
// 	}else{
// 		cout<<"-1\n";
// 	}
// }
void solve(){
	string s1,s2;
	cin>>s1>>s2;
	int l1 = s1.length();
	int l2 = s2.length();

	int m = l1*l2/__gcd(l1,l2);

	string s,r;

	for(int i=0;i<m;i++){

		s.push_back(s1[i%l1]);
		r.push_back(s2[i%l2]);
	}

	if(s == r)
		cout<<s<<"\n";
	else
		cout<<"-1\n";
}
int main(){
	int t;
	cin>>t;

	while(t--)
		solve();
}