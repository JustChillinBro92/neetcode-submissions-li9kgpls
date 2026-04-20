class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        // load all treasure positions in a queue
        for(int r = 0; r < m; r++) {
            for(int c = 0; c < n; c++) {
                if(grid[r][c] == 0)
                   q.push({r, c});
            }
        }

        vector<vector<int>> dir = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        // check all 4 directions level by level
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // check each direction of a level one at a time
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(r < 0 || c < 0 || 
                   r >= m || c >= n ||
                   grid[r][c] != INT_MAX)
                continue;

                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};
