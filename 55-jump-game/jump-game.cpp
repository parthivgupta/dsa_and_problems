class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxLen) return false;
            int canReach = nums[i] + i;
            maxLen = max(maxLen, canReach);
        }
        return true;
    }
};