/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        bool flag = true;

        if(strs.size() == 1) return strs[0];        //如果只有一个元素.直接返回

        while(flag){
            if(strs.size() == 0) break;     //数组为空,直接退出

            for ( int i = 0; i < strs.size() - 1; i++){
                if(strs[i] == "") {     //如果出现空字符,直接退出
                    flag = false;
                    break;
                }
                else if(strs[i].size() <= count ){       //count超过某个字符串的长度
                    flag  = false;
                    break;
                }
                else if(strs[i][count] != strs[i + 1][count]){  //如果两个字符不同,则最长长度到此为止
                    flag = false;
                    break;
                }
            }

            if(flag) count ++;
        }

        if(count == 0) return "";
        char res[1000] = {0};       //有个样例数组string过长,超过了100报错,故开到1000
        // return strs[0].substring(0, count - 1);
        for(int i = 0; i < count; i++){
            res[i] = strs[0][i];
        }
        return (string) res;
    }
};

