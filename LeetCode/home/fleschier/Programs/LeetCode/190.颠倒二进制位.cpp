/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        if(n == 0) return 0;

        uint32_t tmp[100] = {0};
        uint32_t res = 0;
        uint32_t power = 0;     // 初始幂次为0
        int idx = 0;
        while(n != 0){
            tmp[idx++] = n % 2;
            n /= 2;
        }
        for(int i = idx - 1; i >=0; i--){
            if(tmp[i] == 0){
                power++;
                continue;
            }
            else{
                uint32_t tp_int = 1;
                for(int j = 0; j < power; j++){
                    tp_int *= 2;
                }
                power++;
                res += tp_int;
            }
        }
        return res;
    }
};
// @lc code=end

