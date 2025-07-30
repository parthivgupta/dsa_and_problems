class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_val = *max_element(nums.begin(), nums.end());
        int maxLen = 0;
        int currLen = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == max_val) {
                currLen++;
                maxLen = max(maxLen, currLen);
            } else {
                currLen = 0;
            }
        }
        return maxLen;
    }
};
