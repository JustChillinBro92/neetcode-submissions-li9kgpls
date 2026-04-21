class Solution {
private:
    vector<int> dp;
    int dfs(vector<int> &nums, int target, int sum) {
        if(sum > target) return 0;
        if(sum == target) return 1;
        if(dp[sum] != 0) return dp[sum];
        
        for(int start = 0; start < nums.size(); start++) {
            dp[sum] += dfs(nums, target, sum + nums[start]);
        }

        return dp[sum];
    }

public:
    int combinationSum4(vector<int>& nums, int target) {
        dp = vector<int> (target + 1, 0);
        return dfs(nums, target, 0);
    }
};