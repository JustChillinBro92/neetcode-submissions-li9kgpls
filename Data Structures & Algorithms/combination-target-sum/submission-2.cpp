class Solution {
private:
    vector<vector<int>> res;
    vector<int> curr;
    int _target;

    void dfs(vector<int> &nums, int i, int total) {
        if(total == _target) {
            res.push_back(curr);
            return;
        } else if(i >= nums.size() || total > _target) return;

        // operation 1: include same nums[i] as many times you want
        curr.push_back(nums[i]);
        dfs(nums, i, total + nums[i]);

        // operation 2: include any nums[i] except previous nums[i] 
        // as many times you want
        curr.pop_back();
        dfs(nums, i+1, total);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        _target = target;
        dfs(nums, 0, 0);
        return res;
    }
};
