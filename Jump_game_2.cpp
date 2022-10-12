class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums[0] == 0) return 0;
        if(nums.size() == 1) return 0;
        int maxj = nums[0];
        int rmaxj = 1;
        int farthest = nums[0];
        for(int i =1 ; i < nums.size() ; i++)
        {
            if(i == nums.size() - 1) return rmaxj;
            maxj = max(maxj , i+ nums[i]);
            if(farthest == i)
            {
                rmaxj++;
                farthest = maxj;
            }
        }
        return rmaxj;
    }
};
