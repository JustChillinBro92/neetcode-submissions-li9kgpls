class NumMatrix {
private:
    int m, n;
    vector<vector<int>> sumMat;

public:
    NumMatrix(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        sumMat = vector<vector<int>> (m+1, vector<int> (n+1, 0));

        for(int r = 0; r < m; r++) {
            int prefix = 0;
            for(int c = 0; c < n; c++) {
                prefix += mat[r][c];
                int above = sumMat[r][c+1];
                sumMat[r+1][c+1] = prefix + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++; col1++; row2++; col2++;

        int bot_right = sumMat[row2][col2];
        int above = sumMat[row1-1][col2];
        int left = sumMat[row2][col1-1];
        int top_left = sumMat[row1-1][col1-1];

        return bot_right - above - left + top_left;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */