/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        // ascii '0':48
        int lena = a.size();
        int lenb = b.size();

        if(lena > lenb){
            for(int i = 0; i < lena - lenb; i++){
                b = "0" + b;
            }
        }
        if(lenb > lena){
            for(int i = 0; i < lenb - lena; i++){
                a = "0" + a;
            }
        }

        bool carry = false;
        for(int i = a.size() - 1; i >= 0; i--){     //bug: 这里循环不能用lena,应当用a.size(),否则当b比a长的时候就会出错
            if(carry){
                a[i] ++;
                carry = false;
            }
            a[i] = a[i] - 48 + b[i] - 48;       //字符转化为对应的数值
            if(a[i] > 1){
                a[i] %= 2;      
                carry =  true;
            }
            a[i] += 48;       //再转化为字符
        }

        if(carry){
            return "1" + a;
        }
        return a;
    }
};
// @lc code=end

