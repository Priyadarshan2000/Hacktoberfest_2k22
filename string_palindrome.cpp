//string palindrome or NOT


#include<string.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int main()
{
	char str[20];
		int flag;
	cin>>str;
	int n=strlen(str);

	for(int i=0;i<n;i++)
	{
		if(str[i]!=str[n-i-1])
		{
			flag=1;
			break;
		}
		
	}
	if(flag)
	{
		cout<<"It is not Palindrome"<<endl;
		
	}
	else{
		cout<<"YES PALINDROME"<<endl;
	}
}
	
	
