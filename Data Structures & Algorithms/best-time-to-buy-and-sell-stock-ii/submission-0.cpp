class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 1;
        int maxProfit = 0;
        while(sell < prices.size()) {
            // pretend buy first day
            // as soon as a hike in price seen keep accumulating that profit
            if(prices[sell] > prices[sell-1]) {
                maxProfit += (prices[sell] - prices[sell-1]);
            }
            sell++;
        }
        return maxProfit;
    }
};