/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        if(rowIndex == 0) return res;
        for(int i = 0; i < rowIndex; i ++){
            res.push_back(0);
            vector<int> tmp = res;
            reverse(tmp.begin(), tmp.end());
            for(int j = 0; j < res.size(); j++){
                res[j] += tmp[j];
            }
        } 
        return res;
    }
};
// @lc code=end

