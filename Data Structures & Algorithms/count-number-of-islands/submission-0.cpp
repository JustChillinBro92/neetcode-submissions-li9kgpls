class Solution {
private:
    int row, col;

    void dfs(vector<vector<char>> &grid, int r, int c) {
        if(r < 0 || c < 0 ||
           r >= row || c >= col ||
           grid[r][c] == '0')
        return;

        // modify to '0' to signify visited
        grid[r][c] = '0';

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size(); col = grid[0].size();

        int islands = 0;
        for(int r = 0; r < row; r++) {
            for(int c = 0; c < col; c++) {
                if(grid[r][c] == '1') {
                    dfs(grid, r, c);
                    islands++;
                }
            }
        }   
        return islands;
    }
};
