class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        for(auto &str : wordDict) wordSet.insert(str);

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // empty string
        
        for(int len = 1; len <= n; len++) {
            for(int j = 0; j < len; j++) {
                if(dp[j] && wordSet.count(s.substr(j, len - j))) {
                    dp[len] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
