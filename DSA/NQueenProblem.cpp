// 02 N Queen Problem

//You have to place N chess queens on an N×N chessboard so that no two queens attack each other

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int x[10];
int cnt=0;

bool place(int k,int i){
	for(int j=1;j<=k-1;j++){
		if(x[j]==i || abs(k-j)==abs(i-x[j])) return false;
	}
		
	return true;
}



void NQueen(int n,int k){
	for(int i=1;i<=n;i++){
		if(place(k,i)){
			x[k]=i;
			if(k==n){
				cnt++;
				for(int j=1;j<=n;j++){
					cout<<x[j]<<" ";
				}
				cout<<endl;
			}
			else
				NQueen(n,k+1);
		}
	}
	
}

int main(){
	int n;
	cout<<"Enter queens number: ";
	cin>>n;
	
	
	cout<<"The queens position are: "<<endl<<endl;
	NQueen(n,1);
	cout<<"The counts are:"<<cnt<<endl;
	return 0;
}


