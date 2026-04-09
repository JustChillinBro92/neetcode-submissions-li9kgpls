// logic:
// Do I keep currBest and ignore currVal? 
// Or let go of currBest and take the Best before that and add currVal to it?

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0]; 
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            dp[i] = max(
                dp[i - 1], 
                nums[i] + dp[i - 2]
            );
        }

        return dp[n - 1];
    }
};
