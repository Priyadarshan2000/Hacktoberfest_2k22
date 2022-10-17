// C++ code for Pascal's Triangle
#include <iostream>
using namespace std;

int BT(int n, int k);


void PASCALTRI(int n)
{
	
	for (int lone = 0; lone < n; lone++)
	{
		
		for (int i = 0; i <= lone; i++)
			cout <<" "<< BT(lone, i);
		cout <<"\n";
	}
}


int BT(int n, int k)
{
	int res = 1;
	if (k > n - k)
	k = n - k;
	for (int i = 0; i < k; ++i)
	{
		res *= (n - i);
		res /= (i + 1);
	}
	
	return res;
}


int main()
{
	int n = 7;
	PASCALTRI(n);
	return 0;
}


