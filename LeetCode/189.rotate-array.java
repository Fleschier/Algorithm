/*
 * @lc app=leetcode id=189 lang=java
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
    public void rotate(int[] nums, int k) {
        int len = nums.length;
        k = k % len;        //case k > len
        int[] tmp = new int[k];
        for(int i  = 0; i < k; i++){
            tmp[i] = nums[len - k + i]; 
        }
        for(int i = len - 1; i >=k; i--){
            nums[i] = nums[i - k];
        }
        for(int j = 0; j < k; j++){
            nums[j] = tmp[j];
        }
    }
}
// @lc code=end

