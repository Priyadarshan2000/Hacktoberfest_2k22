#include <iostream>
using namespace std;

int fact(int n){
	if(n==0){
		return 1; 
	}
	// 5 = 5 * 4 * 3 * 2 * 1 * (0 == 1)
	return n*fact(n-1);
}

int main(){
	int n;
	cin>>n;
	
	cout << fact(n);
}
