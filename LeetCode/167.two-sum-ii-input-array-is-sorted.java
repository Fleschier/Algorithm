/*
 * @lc app=leetcode id=167 lang=java
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int len = numbers.length;
        int[] res = {0, len - 1};
        while(res[0] < res[1]){
            while(numbers[res[0]] >= 0 && numbers[res[1]] > target){
                res[1]--;
                if(res[1] <= res[0]) return res; //did't find the target
            }
            int tmp = numbers[res[0]] + numbers[res[1]];
            if(tmp == target) {
                res[0]++;
                res[1]++;
                return res;     //为了配合从1开始的下标
            }
            if(tmp > target){
                res[1]--;
                continue;
            }
            if(tmp < target){
                res[0]++;
            }
        }
        return res;     //按照题意则不会运行到这一步
    }
}
// @lc code=end

