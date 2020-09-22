/*
 * @lc app=leetcode id=171 lang=java
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
    public int titleToNumber(String s) {
        int len = s.length();
        int res = 0;
        for(int i = 0; i < len; i++){
            char c = s.charAt(i);
            res *= 26;
            res += (int)c  - 64;
        }
        return res;
    }
}
// @lc code=end

