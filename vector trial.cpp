#include<iostream>
#include<vector>
using namespace std;
int main(){
	
	vector<int>v1={12,22,33,44,55};
	for(int i=0; i<v1.size();++i)
{
	cout<<v1[i];
}
	
cout<<endl;

vector<int>::iterator itr;
for(itr=v1.begin();itr!=v1.end();++itr)
{
	cout<<*itr;
}

}
