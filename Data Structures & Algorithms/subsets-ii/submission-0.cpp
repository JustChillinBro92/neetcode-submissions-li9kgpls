class Solution {
private:
    vector<vector<int>> res;
    vector<int> curr;
    
    void dfs(vector<int> &nums, int i) {
        res.push_back(curr);

        for(int start = i; start < nums.size(); start++) {
            if(start > i && nums[start] == nums[start-1]) continue;

            curr.push_back(nums[start]);
            dfs(nums, start+1);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};
