class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long int cur_sum = 0, max_sum = INT_MIN;
        for (long long int i = 0; i < nums.size(); i ++){
            cur_sum = cur_sum + nums[i];
            if (cur_sum > max_sum){
                max_sum = cur_sum;
            }
            if (cur_sum < 0){
                cur_sum = 0;
            }
        }
        return max_sum;
    }
};