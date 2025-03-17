class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int result = INT_MAX;  
        int curr_sum = 0;
        int curr_len = 0;
        while (right < nums.size()) {  
            curr_sum += nums[right];

            while (curr_sum >= target) {
                curr_len = right - left + 1;
                result = min(result, curr_len); 
                curr_sum -= nums[left];
                left++;
            }
            right++;
        }

        return (result == INT_MAX) ? 0 : result;
    }
};
