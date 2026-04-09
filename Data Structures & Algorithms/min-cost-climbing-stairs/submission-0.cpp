class Solution {
private:
    vector<int> costToEnd;
    int dfs(vector<int> &cost, int i) { 
        if(i > cost.size()-1) return 0;
        if(costToEnd[i] != -1) return costToEnd[i];

        costToEnd[i] = cost[i] + min(
            dfs(cost, i + 1), 
            dfs(cost, i + 2)
        );

        return costToEnd[i];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        costToEnd = vector<int> (cost.size(), -1);
        return min(dfs(cost, 0), dfs(cost, 1));
    }
};
