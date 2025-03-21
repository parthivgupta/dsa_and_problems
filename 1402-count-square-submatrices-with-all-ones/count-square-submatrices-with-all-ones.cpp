class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>&matrix, int row, int col, vector<vector<int>>&dp) {
        if(row >= m || col >= n) {
            return 0;
        }
        if(matrix[row][col] == 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];

        int right = solve(matrix, row, col + 1, dp);
        int down = solve(matrix, row + 1, col, dp);
        int dia = solve(matrix, row + 1, col + 1, dp);

        return dp[row][col] = 1 + min({right, down, dia}); 
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        // vector<vector<int>>dp(m, vector<int>(n, -1));
        // int result = 0;
        // for(int i = 0; i < m; i++) {
        //     for(int j = 0; j < n; j++) {
        //         if(matrix[i][j] == 1) result += solve(matrix, i, j, dp);
        //     }
        // }
        // return result;

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int result = 0;

        // Loop through all cells in the matrix
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    // For the first row or first column, the largest square is just 1 (if it's a 1)
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // Otherwise, use the min of left, up, and diagonal values to calculate the largest square
                        int left = dp[i][j - 1];
                        int up = dp[i - 1][j];
                        int dia = dp[i - 1][j - 1];
                        dp[i][j] = 1 + min({left, up, dia});
                    }
                    result += dp[i][j];  // Add the size of the square ending at (i, j)
                }
            }
        }
        return result;
    }


};