class Solution {
private:
    int row, col;

    int dfs(vector<vector<int>> &grid, int r, int c) {
        if(r < 0 || c < 0 ||
           r >= row || c >= col || 
           grid[r][c] == 0)
        return 0;

        grid[r][c] = 0;  

        return 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) +
            dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size(); col = grid[0].size();

        int maxArea = 0;
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col ; c++) {
                if(grid[r][c] == 1)
                    maxArea = max(maxArea, dfs(grid, r, c));   
            }
        } 
        return maxArea;
    }
};
