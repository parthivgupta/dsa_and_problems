class Solution {
public:
    int solve(vector<int>&coins, int ind, int amount) {
        if(ind == 0) {
            if(amount % coins[ind] == 0) return amount / coins[ind];
            return 1e9;
        }
        int not_pick = solve(coins, ind - 1, amount);
        int pick = 1e9;
        if(amount >= coins[ind]) {
           pick =  1 + solve(coins, ind, amount - coins[ind]); 
        }
        return min(pick, not_pick);

    }
    int coinChange(vector<int>& coins, int amount) {
        // int a = solve(coins, coins.size() - 1, amount);
        // if(a == 1e9) return -1;
        // else return a; 
        int n = coins.size();


        // tabulation
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0) {
                dp[0][i] = i / coins[0];
            } else dp[0][i] = 1e9;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                int not_pick = dp[i - 1][j];
                int pick = 1e9;
                if(j >= coins[i]) {
                    pick =  1 + dp[i][j- coins[i]]; 
                }
                dp[i][j] = min(pick, not_pick);
            }
        }
        int ans = dp[n -1][amount];
        if(ans == 1e9) return -1;
        else return ans;
    }
};