/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
//判断是否回文
// 'A': 65  'a': 97
    // bool isEqual(char a, char b){     //不区分大小写比较两个字母是否相同
    //     if(a == b) return true;
    //     //数字有坑, 例如'0' 和'P' 
    //     if(isdigit(a) && !isdigit(b)) return false;
    //     if(isdigit(b) && !isdigit(a)) return false;
    //     if(abs(b - a) == 32) return true;       //差的绝对值等于32则说明是同个字母的大小写
    //     return false;
    // }
    bool isPalindrome(string s) {
        if(s == "") return true;
        int front = 0, rear = s.size() - 1;
        while(front < rear){
            // 用库函数判断
            while(!isalnum(s[front]) && front < rear) front ++;
            while(!isalnum(s[rear]) && front < rear) rear--;
            if(front >= rear) return true;
           //if(!isEqual(s[front++], s[rear--])) return false;
           if(toupper(s[front++]) != toupper(s[rear--])) return false;
        }
        return true;
    }
};
// @lc code=end

// 记一笔 c++的几个内置函数:
// islower(char c) 是否为小写字母
// isuppper(char c) 是否为大写字母
// isdigit(char c) 是否为数字
// isalpha(char c) 是否为字母
// isalnum(char c) 是否为字母或者数字
// toupper(char c) 字母小转大
// tolower(char c) 字母大转小

// 分享个字母大小写转换的方法：
// 统一转成大写：ch & 0b11011111 简写：ch & 0xDF
// 统一转成小写：ch | 0b00100000 简写：ch | 0x20
// 比较的时候注意加上小括号哦，因为位运算优先级比较低。