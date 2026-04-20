class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int total_rows = matrix.size();
        int total_cols = matrix[0].size();

        // limits of 1d version of 2d matrix
        int lb = 0, ub = total_rows * total_cols - 1;
        
        while(lb <= ub) {
            int mid = (lb + ub) / 2;
            int row = mid / total_cols;
            int col = mid % total_cols;

            if(matrix[row][col] == target) return true;
            else if(target < matrix[row][col]) ub = mid - 1;
            else lb = mid + 1; 
        }
        return false;
    }
};
