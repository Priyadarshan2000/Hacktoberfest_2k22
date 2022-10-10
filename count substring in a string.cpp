#include<iostream>
using namespace std;
int countsubstring(string &s,string &sub){
	int c=0;
	int sublength=sub.length();
	for(int i=0;i<=s.length()-sublength;i++){
		if(sub==s.substr(i,sublength)) c++;
	}
	return c;
}
int main(void){
	string s;
	cout<<"Enter the string-";
	getline(cin,s);
	cout<<"Enter the substring-";
	string sub;
	cin>>sub;
	cout<<countsubstring(s,sub);
}
