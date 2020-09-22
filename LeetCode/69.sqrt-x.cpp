/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        if(x == 1) return 1;

        int res;
        for(long i = 1; i <= x/2; i++){
            if(i * i <= x && (i + 1) * (i + 1) > x){
                res = i;
                break;
            }
        }
        return res;
    }
};
// @lc code=end

