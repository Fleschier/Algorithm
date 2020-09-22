/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    // int Max(int a, int b){
    //     return a >= b ? a : b;
    // }
    int maxSubArray(vector<int>& nums) {
        
        // 法一: 贪心法
        int current_max = nums[0], max = nums[0];
        for(int i = 1; i < nums.size(); i++){
            // current_max = Max(current_max + nums[i], nums[i]);
            // max = Max(current_max, max);
            current_max = (nums[i] + current_max) >= nums[i] ? (nums[i] + current_max) : nums[i];
            max = current_max >= max ? current_max : max;
        }

        return max;
    }
};
// @lc code=end

