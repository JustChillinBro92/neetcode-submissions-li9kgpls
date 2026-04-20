class Solution {
private:
    bool dfs(vector<int> &matchsticks, vector<int> &sides, int side_len, int start) {
        if(start == matchsticks.size())
            return true;

        for(int side = 0; side < 4; side++) {
            if(sides[side] + matchsticks[start] <= side_len) {
                sides[side] += matchsticks[start];           // choose
                if(dfs(matchsticks, sides, side_len, start + 1))
                    return true;
                sides[side] -= matchsticks[start];        // backtrack if branch fails

                if(sides[side] == 0) break;             // pruning
            }
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(sum % 4 != 0) return false;

        sort(matchsticks.rbegin(), matchsticks.rend()); // optimization

        int side_len = sum / 4;
        vector<int> sides(4, 0);
        return dfs(matchsticks, sides, side_len, 0);
    }
};