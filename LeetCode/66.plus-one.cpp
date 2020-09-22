/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int len = digits.size();

        bool special = true;
        for(int i = 0; i < len; i++){
            if(digits[i] != 9){
                special = false;
                break;
            }
        }
        if(special){
            vector<int> res;
            res.resize(len + 1);
            res[0] = 1;
            return res;
        }

        vector<int> result = digits;
        result[len - 1] += 1;
        bool  carry = false;

        for(int i = len - 1; i >= 0; i--){
            if(carry){
                result[i] += 1;
                carry = false;
            }
            if(result[i] == 10){
                result[i] = 0;
                carry = true;
            }
        }
        
        return result;
    }
};
// @lc code=end

