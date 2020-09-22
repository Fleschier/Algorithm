/*
 * @lc app=leetcode id=172 lang=java
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution{ 
    public int trailingZeroes(int n) {
        int res = 0;
        int tmp = n;
        while(tmp != 0){
            tmp /= 5;
            res += tmp;
        }
        return res;
    }
}
// @lc code=end

//不能依赖于把阶乘算出来再求解,因为阶乘计算很容易溢出
//思路:其实就是找2和5的个数,而因子中2的个数远超5的个数,故只需要找出因子中含有5的个数即可
//又注意点: 25相当于2个5,125相当于3个5...
// 50 / 5 = 10
// 5  10 15 20 25 30 35 40 45 50
// 25 = 5*5
// 50 = 5 * 5 * 2
//相当于有 10 + 2 = 12个5