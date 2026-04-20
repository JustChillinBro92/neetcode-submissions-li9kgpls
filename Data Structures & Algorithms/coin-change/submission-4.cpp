class Solution {
private:
    int minVal = INT_MAX;
    vector<vector<int>> dp;

    void minCoins(vector<int> &coins, int amt, int coin, int count, int i) {
        if(coin > amt || i == coins.size()) return;
        if(count >= minVal) return;
        if(coin == amt) {
            minVal = min(minVal, count);
            return;
        } 

        // if same state already reached with fewer coins before stop
        if(dp[i][coin] != -1 && dp[i][coin] <= count) return;
        dp[i][coin] = count;
        
        // explore
        coin += coins[i];
        minCoins(coins, amt, coin, count + 1, i);

        // backtrack
        coin -= coins[i];
        minCoins(coins, amt, coin, count, i + 1);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        dp = vector<vector<int>> (n, vector<int> (amount + 1, -1));

        sort(coins.rbegin(), coins.rend());
        minCoins(coins, amount, 0, 0, 0);
        return minVal == INT_MAX ? -1 : minVal;
    }
};
