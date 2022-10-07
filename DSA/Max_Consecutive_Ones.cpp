/*
Solution with explanation to problem --> :Max Consecutive Ones" on leetcode
*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_cnt = 0, cnt = 0; // max_cnt to store all time max and cnt to store current max consecutive ones
        for (auto n : nums) {
            if (n == 1) max_cnt = max(++cnt, max_cnt);//for each window of 1's we compare current length of 1's with max length
            else cnt = 0;  //we make current max zero if zero is encountered
        }
        return max_cnt;
    }
};
