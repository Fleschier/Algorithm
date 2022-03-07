/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:

    void clear(int arr[], int len){
        for(int i = 0; i < len; i++){
            arr[i] = 0;
        }
    }

    int lengthOfLongestSubstring(string s) {
        int record[200] = {0};  // the elements in this record[] record the 
                                //index of the charactor appears in the current substring
                                // start from 1
        int len = s.length();
        if(len == 0){
            return 0;
        }

        int max_len = 0;
        int current_len = 0;

        for(int i = 0; i < len;){
            if(record[(int)s[i]] != 0){
                i -= (current_len - record[(int)s[i]]);
                max_len = max_len > current_len ? max_len : current_len;
                current_len = 0;
                clear(record, 200);
            }
            else{
                record[(int)s[i]] = ++current_len;
                i++;
            }

        }
        max_len = max_len > current_len ? max_len : current_len;

        return max_len;
    }
};
// @lc code=end

