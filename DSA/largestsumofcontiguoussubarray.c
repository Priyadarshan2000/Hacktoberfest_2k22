#include <stdio.h>
#define ARRAY_SIZE(a)  sizeof(a)/sizeof(a[0])
int maxSubArraySum (int arr[], int n)
{
  int i = 0;
  int max_so_far = 0;
  int max_ending_here = 0;

  for (i = 0; i & lt; n; i++)
    {
      max_ending_here = max_ending_here + arr[i];
      if (max_ending_here & lt; 0)
	{
	  max_ending_here = 0;
	}
      if (max_so_far & lt; max_ending_here)
	{
	  max_so_far = max_ending_here;
	}
    }
  return max_so_far;
}

int main ()
{
  int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  int arr_size = ARRAY_SIZE (arr);
  const int maxSum = maxSubArraySum (arr, arr_size);
  printf ("Largest Sum Contigous SubArray : %d ", maxSum);
  return 0;
}
