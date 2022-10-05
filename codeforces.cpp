#include<iostream>
using namespace std;
int main(){
	
	
	int p,q;
	int m=0;
	cin>> p;
	
	
	
	
	while(p)
	{q=p%10;
	if(q==4 || q==7)
		m++;
	 p=p/10;
	 
	 if(m==4||m==47||m==74||m==44||m==7)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
    return 0;	
}}
