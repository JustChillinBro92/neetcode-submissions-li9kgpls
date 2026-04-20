class Solution {
private:
    int row, col;
    set<pair<int, int>> path;
    string _word;

    bool dfs(vector<vector<char>> &board, int r, int c, int i) {
        if(i == _word.size()) return true;

        if(r < 0 || c < 0 ||
           r >= row || c >= col ||
           board[r][c] != _word[i] ||
           path.count({r, c})) return false;
        
        path.insert({r, c});
        
        bool res = (dfs(board, r + 1, c, i + 1) || 
                    dfs(board, r - 1, c, i + 1) ||
                    dfs(board, r, c + 1, i + 1) ||
                    dfs(board, r, c - 1, i + 1));
        
        path.erase({r, c});
        return res;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        _word = word; row = board.size(); col = board[0].size();

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(dfs(board, i, j, 0)) return true;
            }
        }
        return false;
    }
};
