class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int window = 0, pane = 1, maxProfit = 0;

        while(pane < prices.size()) {
            if(prices[pane] > prices[window]) {
                int profit = prices[pane] - prices[window];
                maxProfit = max(profit, maxProfit);
            } else window = pane;
            pane++;
        }
        return maxProfit;
    }
};
