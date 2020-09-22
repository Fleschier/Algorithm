/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s == "") return 0;

        int len = 0;

        // int n = s.size();
        // for(int j  = s.size() - 1; j >= 0; j--){
        //     if(s[j] == ' ') --n;
        //     else break;
        // }
        // for(int i = 0; i < n; i++){
        //     if(s[i] != ' ') len++;
        //     else if(s[i] == ' ') len = 0;
        // }
        bool flag = false;
        for(int i = s.size()- 1; i >= 0; i--){
            if(s[i] != ' ') flag = true;
            if(flag && s[i] != ' ') len ++;
            if(s[i] == ' ' && len != 0) break;
        }

        return len;
    }
};
// @lc code=end

