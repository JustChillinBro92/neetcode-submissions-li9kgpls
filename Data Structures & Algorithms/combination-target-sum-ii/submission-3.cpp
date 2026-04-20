class Solution {
private:
    vector<vector<int>> res;
    vector<int> curr;
    int _target;

    void dfs(vector<int> &candidates, int i, int total) {
        if(total == _target) {
            res.push_back(curr);
            return;
        }

        for(int start = i; start < candidates.size(); start++) {
            // skip duplicates
            if(start > i && candidates[start] == candidates[start-1]) continue;

            // little QOL feature, early break instead of recursive call
            if(total + candidates[start] > _target) break;

            curr.push_back(candidates[start]);
            dfs(candidates, start+1, total + candidates[start]);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        _target = target;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0);
        return res;
    }
};
