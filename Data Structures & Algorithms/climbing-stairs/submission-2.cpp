class Solution {
private:
    vector<int> ways;
    int dfs(int n, int i) {
        if(i == n) return 1;
        if(i > n) return 0;
        // optimization 
        if(ways[i] != -1) return ways[i];
        ways[i] = dfs(n, i + 1) + dfs(n, i + 2);

        return ways[i];
    }

public:
    int climbStairs(int n) {
        ways = vector<int> (n, -1);
        return dfs(n, 0);
    }
};
