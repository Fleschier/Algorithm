/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.21%)
 * Total Accepted:    642.7K
 * Total Submissions: 2.5M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
class Solution {
public:
    int reverse(int x) {
        char tmp[20] = {0};
        sprintf(tmp, "%d", x);
        int end = 0;
        int res = 0;
        bool neg = false;
        if(tmp[0] == '-') {
            neg = true;
            end = 1;
        }
        
        if(strlen(tmp) >= 10)
            if(tmp[strlen(tmp) - 1] >= '3') 
                return 0;

        for(int i = strlen(tmp) - 1; i >= end; i--){ 
            //int pre = res;
            if(res > 214748364) return 0;
            res = res * 10 + (tmp[i] - '0');
            //if(res/10 != pre) return 0;     //如果溢出则返回0
        }
        if(neg) res = -res;
        return res;
    }
};

