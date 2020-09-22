/*
 * @lc app=leetcode id=168 lang=java
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
    public String convertToTitle(int n) {
        StringBuffer buff = new StringBuffer();
        String s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int count = n;
        int value = 0;
        while(true){        //n >= 27
            value = count % 26;             //26 % 26 = 0  input : 26 -> index : 25
            count = count / 26;
            if(value == 0){
                value = 26;
                count--;
            }
            buff.append(s.charAt(value - 1));
            if(count == 0) break;
            value  = count;
        }
        buff.reverse();
        return buff.toString();
    }
}
// @lc code=end

