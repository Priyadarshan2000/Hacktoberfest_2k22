#include <iostream>
using namespace std;

bool isPossible(int elements[], int sum, int n)
{
	int dp[sum + 1];
	dp[0] = 1;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = sum; j >= elements[i]; j--)
		{
			if (dp[j - elements[i]] == 1)
				dp[j] = 1;
		}
	}
	
	if (dp[sum] == 1)
		return true;
		
	return false;
}

int main()
{
	int elements[] = { 6, 2, 5 };
	int n = sizeof(elements) / sizeof(elements[0]);
	int sum = 7;
	
	if (isPossible(elements, sum, n))
		cout << ("YES");
	else
		cout << ("NO");

	return 0;
}