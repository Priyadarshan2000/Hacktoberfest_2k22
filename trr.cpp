#include<iostream>
using namespace std;
int main()
{
   int num;
   cin>>num;
   int n=num;
   int rev=0;
   while(num!=0)
   {
   	int i=num%10;
   	rev=(rev*10)+i;
   	num=num/10;
   	
   }
   if(n==rev)
   {
   	cout<<"it is palindrome"<<endl;
   	
   }
   else{
   	cout<<"NOT PALINDROME"<<endl;
   }
}
