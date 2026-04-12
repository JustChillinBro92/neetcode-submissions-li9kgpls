class Solution {
private:
    unordered_map<int, int> dp;

    int minCoins(vector<int> &coins, int amt) {
        if(amt == 0) return 0;
        if(dp.count(amt)) return dp[amt];
        
        int res = INT_MAX;
        for(auto &coin : coins) {
            if(amt - coin >= 0) {
                int result = minCoins(coins, amt - coin);
                if(result != INT_MAX)
                    res = min(res, 1 + result);
            }
        }

        dp[amt] = res;
        return res;
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int ans = minCoins(coins, amount);
        return ans == INT_MAX ? -1 : ans;
    }
};