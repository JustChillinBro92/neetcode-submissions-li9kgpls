class Solution {
private:
    vector<vector<int>> res;

    void dfs(vector<int> &nums, int i) {
        if(i >= nums.size()) {
            res.push_back(nums);
            return;
        }

        for(int index = i; index < nums.size(); index++) {
            swap(nums[index], nums[i]); // choose
            dfs(nums, i + 1);       // explore
            swap(nums[index], nums[i]); // unchoose (backtrack)
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};
