/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = 0, sell = 1;      // index of buying day and selling day
        //int max_buy = 0, max_sell = 1;
        int len = prices.size();
        while(buy < len - 1){
            if((prices[sell] - prices[buy]) > profit){
                profit = prices[sell] - prices[buy];
                // max_buy = buy;
                // max_sell = sell;
            }
            if(sell == len -1){
                ++buy;
                sell = buy + 1;
                continue;
            }
            ++sell;
        }
        return profit;
    }
};
// @lc code=end

