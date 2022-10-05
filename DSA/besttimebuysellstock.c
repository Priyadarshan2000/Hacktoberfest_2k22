#include <stdio.h>
#include<limits.h>

int maxProfit(int *prices, int n) {

  int max_sp[n];
  int maximum = INT_MIN;

  // Construct the maxSP array
  for (int i = n - 1; i >= 0; i--) {
      if (prices[i] > maximum) {
         maximum = prices[i];
         max_sp[i] = INT_MIN;
      } 
      else {
         max_sp[i] = maximum;
      }
  }

  int profit = 0;
  for (int i = 0; i < n; i++) {

    if (max_sp[i] != INT_MIN && profit <(max_sp[i] - prices[i])) {
      profit = max_sp[i] - prices[i];
   }

  }

  // Return profit
  return profit;
}

int main() {

   int n;
   scanf("%d", &n);

   int prices[n];

   for(int i=0; i<n; i++)
   scanf("%d", &prices[i]);

   // Calculating the max profit
   int ans = maxProfit(prices, n);

   // Print the answer
   printf("%d", ans);
   return 0;
}
