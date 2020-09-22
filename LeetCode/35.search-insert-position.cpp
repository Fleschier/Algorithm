/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target <= nums[0]) return 0;
        if(target == nums[nums.size() - 1]) return nums.size() - 1;
        if(target > nums[nums.size() - 1]) return nums.size();
        if(nums.empty()) return 0;
    
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == target) return i;
            else if(nums[i] < target && nums[i + 1] > target) return (i + 1);
        }
        return 0;       //只是为了函数返回值合法,无实际意义.
    }
};
// @lc code=end

