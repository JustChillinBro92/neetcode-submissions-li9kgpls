class Solution {
private:
    vector<vector<int>> dp;
    bool possible(vector<int> &nums, int target, int i) {
        if(i == nums.size()) {
            if(target == 0) return true;
            else return false;
        }
        if(target < 0) return false;
        
        if(dp[i][target] != -1) return dp[i][target];
        
        dp[i][target] = (
            possible(nums, target - nums[i], i + 1) ||
            possible(nums, target, i + 1)
        );

        return dp[i][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;

        int target = sum / 2;
        dp = vector<vector<int>> (nums.size(), vector<int>(target + 1, -1));
        return possible(nums, target, 0);
    }
};
