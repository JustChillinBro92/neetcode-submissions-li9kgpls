class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, int start) {
        if(start == nums.size()) {
            res.push_back(nums);
            return;
        }

        unordered_set<int> used;
        for(int i = start; i < nums.size(); i++) {
            // if(i > start && nums[i] == nums[i-1]) continue;
            if(used.find(nums[i]) != used.end()) continue;
            used.insert(nums[i]);

            swap(nums[i], nums[start]);
            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};