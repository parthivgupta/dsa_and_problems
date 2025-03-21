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
        int n = nums.size();
        vector<int> dp(n, -1);
        return minJumps(nums, 0, dp);
    }
};