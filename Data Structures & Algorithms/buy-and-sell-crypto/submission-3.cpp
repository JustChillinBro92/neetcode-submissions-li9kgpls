class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int l = 0, r = 1;
        while(r < prices.size()) {
            int p = prices[r] - prices[l];
            if(p < 0) l = r;
            else maxP = max(maxP, p);
            r++;
        }
        return maxP;
    }
};
