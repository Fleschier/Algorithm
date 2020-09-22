/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack == "") return -1;

        int len = needle.size();

        bool flag = true;
        int idx = -1;

        for(int i = 0; i < haystack.size(); i++){
            if(haystack.size() - i < len) return -1;      //剩余未比较长度小于查找子串
            if(haystack[i] == needle[0]){
                flag = true;
                for(int j = 1; j < len; j++){
                    if(haystack[i + j] != needle[j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    idx = i;
                    return idx;
                }
            }
        }
        
        return idx;

    }
};
// @lc code=end

