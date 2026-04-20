class Solution {
private:
    int row, col;
    vector<vector<bool>> visited;

    int dfs(vector<vector<int>> &grid, int r, int c) {
        if(r < 0 || c < 0 || 
           r >= row || c >= col ||
           grid[r][c] == 0)
        return 1;

        if(visited[r][c]) return 0;

        visited[r][c] = true;

        return dfs(grid, r + 1, c) + dfs(grid, r - 1, c) +
               dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
    }

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size(); 
        col = grid[0].size();
        visited = vector<vector<bool>> (row, vector<bool>(col, false));

        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if(grid[r][c] == 1)
                    return dfs(grid, r, c);
            }
        }
        return 0;
    }
};