/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string res = "1";
        for(int i = 1; i < n; i++){
            string tmp = "";
            int count = 1;
            char tmp_ch = res[0];
            for(int j = 1; j < res.size(); j++){
                if(res[j] == tmp_ch){
                    count++;
                }
                else{
                    tmp += (char) (count + 48);     //string可以直接加减char
                    tmp += tmp_ch;
                    tmp_ch = res[j];
                    count = 1;
                }
            }
            tmp += (char) (count + 48);
            tmp += tmp_ch;
            res = tmp;
        }
        return res;
    }
};
// @lc code=end

