class Solution {
public:
    int minimumCardPickup(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        unordered_map<int, int> mpp;
        while (right < nums.size()) {
            mpp[nums[right]]++;
            while (mpp[nums[right]] > 1) {
                ans = min(ans, right - left + 1);
                mpp[nums[left++]]--;
            }
            right++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};