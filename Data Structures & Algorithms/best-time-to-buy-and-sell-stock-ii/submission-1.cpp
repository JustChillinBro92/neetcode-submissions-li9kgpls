class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int l = 1;
        while(l < prices.size()) {
            if(prices[l] > prices[l-1])
                maxP += (prices[l] - prices[l-1]);
            l++;
        }
        return maxP;
    }
};