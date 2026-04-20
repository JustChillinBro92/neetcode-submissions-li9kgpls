class Solution {
private:
    vector<vector<int>> res;
    vector<int> subset;

    void dfs(vector<int> &nums, int i) {
        if(i >= nums.size()) {
            res.push_back(subset);
            return;
        }
        // operation 1: include nums[i]
        subset.push_back(nums[i]);
        dfs(nums, i+1);

        // operation 2: not include nums[i]
        subset.pop_back();
        dfs(nums, i+1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};
