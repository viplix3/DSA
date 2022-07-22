// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMinPrice = prices[0], maxProfit = 0, numStocks = prices.size();
        
        for(int i = 1; i < numStocks; i++) {
            maxProfit = max(prices[i] - currMinPrice, maxProfit);
            currMinPrice = min(prices[i], currMinPrice);
        }
        
        return maxProfit;
    }
};