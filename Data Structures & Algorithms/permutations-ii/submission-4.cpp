class Solution {
private:
    vector<vector<int>> res;
    void dfs(vector<int> &nums, vector<int> &curr, vector<bool> &visited) {
        if(curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            // skip branch if already visited (since we scan from start each recurison)
            if(visited[i]) continue;

            // skip branch if its previous duplicate branch not visited before
            // duplicate branches must be visited in order
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

            visited[i] = true;             
            curr.push_back(nums[i]);     // explore
            dfs(nums, curr, visited);
            visited[i] = false;         
            curr.pop_back();        // un-explore(backtrack)
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<bool> visited(nums.size(), false);
        dfs(nums, curr, visited);
        return res;
    }
};