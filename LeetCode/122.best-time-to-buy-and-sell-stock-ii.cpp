/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int profit = 0;
        int begin = 0, end = 0;
        while(begin < prices.size() - 1){
            while(begin < prices.size() - 1 && prices[begin] >= prices[begin + 1]){      //找到第一个波谷
                begin++;
            }
            if(begin > prices.size() - 2) break;   //如果已经到了最后一个,说明是递减的,直接退出.
            end = begin;
            while(end < prices.size() - 1 && prices[end] <= prices[end + 1]){   //找到第一个波峰
                end++;
            }
            profit += prices[end] - prices[begin];
            begin = end + 1;
        }
        return profit;

    }
};
// @lc code=end

