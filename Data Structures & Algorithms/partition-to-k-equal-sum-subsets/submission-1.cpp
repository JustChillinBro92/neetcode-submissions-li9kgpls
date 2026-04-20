class Solution {
private:
    int target_len;
    bool dfs(vector<int> &nums, vector<int> &subset, int start) {
        if(start == nums.size()) return true;

        for(int sub = 0; sub < subset.size(); sub++) {
            if(subset[sub] + nums[start] <= target_len) {
                subset[sub] += nums[start];
                if(dfs(nums, subset, start + 1))
                    return true;
                subset[sub] -= nums[start];
            }
        }
        return false;
    }

public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;

        sort(nums.rbegin(), nums.rend());

        target_len = sum / k;
        vector<int> subset(k, 0);
        return dfs(nums, subset, 0);
    }
};