class Solution {
private:
    int maxRob(vector<int> &nums, int l, int r) {
        int n = nums.size();
        if(l == n - 1) return nums[l];

        vector<int> dp(n);
        dp[l] = nums[l];
        dp[l + 1] = max(nums[l], nums[l + 1]);

        for(int i = l + 2; i <= r; i++) {
            dp[i] = max (
                dp[i - 1],
                dp[i - 2] + nums[i]
            );
        }

        return l == 0 ? dp[n - 2] : dp[n - 1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        return max (
            maxRob(nums, 0, n - 2),
            maxRob(nums, 1, n - 1)
        );
    }
};
