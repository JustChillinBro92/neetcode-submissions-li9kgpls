class Solution {
private:
    int countWays(string s, unordered_map<int, int> &dp, int i) {
        if(dp.count(i)) return dp[i];
        if(s[i] == '0') return 0;

        // count single digit ways 1st
        int res = countWays(s, dp, i + 1);

        // count double digit ways next
        if(i < s.size() - 1) {
            if(s[i] == '1' || 
              (s[i] == '2' && s[i + 1] <= '6'))
            res += countWays(s, dp, i + 2);
        }
        dp[i] = res;

        return res;
    }

public:
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return countWays(s, dp, 0);
    }
};
