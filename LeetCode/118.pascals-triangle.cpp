/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //常规思路
        //vector<vector<int>> res;   
        //if(numRows == 0) return res;
        // vector<int> tmp;
        // tmp.push_back(1);
        // res.push_back(tmp);
        // if(numRows == 1) return res;

        // tmp.push_back(1);
        // res.push_back(tmp);
        // if(numRows == 2) return res;

        // vector<int> element = tmp;
        // tmp.clear();
        // for(int i = 2; i < numRows; i++){
        //     tmp.push_back(1);
        //     for(int j = 0; j < element.size() - 1; j++){
        //         tmp.push_back(element[j] + element[j + 1]);
        //     }
        //     tmp.push_back(1);
        //     res.push_back(tmp);
        //     element = tmp;
        //     tmp.clear();
        // }

        // 错位相加法       0 1 1 + 1 1 0  = 1 2 1 (以第二行生成第三行为例)
        vector<vector<int>> res;
        if(numRows == 0) return res;
        vector<int> tmp = {1};
        res.push_back(tmp);
        if(numRows == 1) return res;
        for(int i  = 1; i < numRows; i++){
            tmp.push_back(0);
            vector<int> tmp2 = tmp;
            reverse(tmp2.begin(), tmp2.end());
            for(int j = 0; j < tmp.size(); j++){
                tmp[j] += tmp2[j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end

