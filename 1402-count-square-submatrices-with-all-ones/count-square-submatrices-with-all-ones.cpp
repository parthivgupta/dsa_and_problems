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
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int result = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1) result += solve(matrix, i, j, dp);
            }
        }
        return result;
    }
};