// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.

#include <bits/stdc++.h>
using namespace std;

int ans = 1e5;
int threeSumClosest(vector<int> &nums, int target)
{
    int n = nums.size(), ans = 1e5;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == target)
            {
                return sum;
            }
            if (abs(sum - target) < abs(ans - target))
            {
                ans = sum;
            }
            sum < target ? l++ : r--;
        }
    }
    return ans;
}

int main(){
    vector<int> arr ={1,-2,2,1,-4};
    int target=2;
    cout<<threeSumClosest(arr,target)<<endl;
}
