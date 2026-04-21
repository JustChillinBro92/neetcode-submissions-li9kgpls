class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for(int target = 1; target <= n; target++) {
            for(int s = 1; s <= target; s++) {
                int sq = s * s;
                if(target - sq < 0) break;
                dp[target] = min(dp[target], 1 + dp[target - sq]);
            }
        }
        return dp[n];
    }
};