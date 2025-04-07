class Solution {
public:
    bool solve(int ind, int target, vector<int>&nums, vector<vector<int>>&dp) {
        if(target == 0) return true;
        if(ind == 0) return nums[0] == target;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool notTaken = solve(ind - 1, target, nums, dp);
        bool taken = false;
        if (nums[ind] <= target)
            taken = solve(ind - 1, target - nums[ind], nums, dp);
        
        return dp[ind][target] = notTaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }
        if(totalSum % 2 != 0) return false;
        int n = nums.size();
        int k = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(n - 1, k, nums, dp);
    }
};
