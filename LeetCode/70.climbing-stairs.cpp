/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
        int traverse(int n, int tmp[]){
            if(n == 0) return 1;
            if(n == 1) return 1;
            if(n == 2) return 2;
            int res = 0;
            if(tmp[n] != 0){
                res = tmp[n];
            }
            else{
                tmp[n] = traverse(n - 1, tmp) + traverse(n - 2, tmp);
                res = tmp[n];
            }
            return res;
        }
    int climbStairs(int n) {
        int tmp[1000] = {0};
        return traverse(n, tmp);
    }
};
// @lc code=end

