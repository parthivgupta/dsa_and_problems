class Solution {
public:
    int minJumps(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size() - 1) return 0;

        
        if (dp[i] != -1) return dp[i];

        int jumps = INT_MAX;
        int maxJump = min(i + nums[i], (int)nums.size() - 1);

        for (int j = i + 1; j <= maxJump; j++) {
            int result = minJumps(nums, j, dp); 
            if (result != INT_MAX) {
                jumps = min(jumps, 1 + result);
            }
        }

        dp[i] = jumps;
        return dp[i];
    }
    int jump(vector<int>& nums) {
        /*
        vector<int> dp(n, -1);
        return minJumps(nums, 0, dp);

    */

        int n = nums.size();

    // TABULATION
    
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = 0;  // No jumps needed to reach the last index from the last index
        
        // Iterate backwards from second last index to the first index
        for (int i = n - 2; i >= 0; --i) {
            int maxJump = min(i + nums[i], n - 1); // Max reachable index from i
            
            // Check all reachable indices from i and update dp[i]
            for (int j = i + 1; j <= maxJump; ++j) {
                if (dp[j] != INT_MAX) {  // Ensure we are not adding to INT_MAX
                    dp[i] = min(dp[i], 1 + dp[j]);  // 1 for the jump from i to j
                }
            }
        }
        
        return dp[0];  // The minimum jumps from the first index
    }

};