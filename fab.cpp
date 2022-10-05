
		#include<iostream>
		using namespace std;
#include<conio.h>
int main()
{
    int num1,num2,nextnum,n,i;
    cout<<"Enter the value for range:"; //Fibonacci series range value will be inputted
    cin>>n;
    num1=0;
    num2=1;
    cout<<"Fibonacci series is:"<<endl;
    if(n==1)    
        cout<<num1<<endl;  //Single value will be printed if range value is 1
    else if(n==2)
        cout<<num1<<"\t"<<num2<<endl;  //Two values will be printed if the range value is two
    else
    {
        cout<<num1<<"\t"<<num2<<"\t";
        for(i=3;i<=n;i++)    //Fibonacci series will be printed based on range limit
        {
            nextnum=num1+num2;
            cout<<nextnum<<"\t";
            num1=num2;
            num2=nextnum;
        }
    }
    getch();
}

