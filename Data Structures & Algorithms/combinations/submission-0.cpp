class Solution {
private:
    vector<vector<int>> res;
    void dfs(int n, int k, vector<int> curr, int start) {
        if(curr.size() == k) {
            res.push_back(curr);
            return;
        }

        for(int i = start; i <= n; i++) {
            curr.push_back(i);
            dfs(n, k, curr, i + 1);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, {}, 1);
        return res;
    }
};