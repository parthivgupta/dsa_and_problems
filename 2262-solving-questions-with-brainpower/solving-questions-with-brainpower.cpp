class Solution {
public:
    long long solve(vector<vector<int>>&questions, int i, vector<long long>&dp) {
        if(i >= questions.size()) return 0;

        if(dp[i] != -1) return dp[i];

        long long skip = solve(questions, i + 1, dp);
        long long choose = questions[i][0] + solve(questions, i + questions[i][1] + 1, dp);
        return dp[i] = max(skip, choose);

    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        // vector<long long>dp(n, -1);
        // return solve(questions, 0, dp);

        // tabulation
          vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            long long skip = dp[i + 1];
            long long choose = questions[i][0];
            if (i + questions[i][1] + 1 <= n) {
                choose += dp[i + questions[i][1] + 1];
            }
            dp[i] = max(skip, choose);
        }
        return dp[0];
    }
};