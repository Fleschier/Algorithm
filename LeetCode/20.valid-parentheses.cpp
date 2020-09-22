/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        if(s == "") return true;        //空字符串是匹配的
        if(s.size() == 1) return false;     //字符长度等于1必不匹配

        char Lbracket[5000] = {0};
        int Lidx = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                Lbracket[Lidx] = s[i];
                Lidx ++;
            }
            if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(Lidx > 0){
                    if(s[i] == ')' && Lbracket[Lidx - 1] != '(' ) return false;
                    else if(s[i] == ']' && Lbracket[Lidx - 1] != '[') return false;
                    else if(s[i] == '}' && Lbracket[Lidx -1] != '{') return false;
                    else Lidx --;       //匹配成功
                }
                else return false;
            }
        }
        if(Lidx != 0) return false;         //未匹配完全
        return true;
    }
};
// @lc code=end

