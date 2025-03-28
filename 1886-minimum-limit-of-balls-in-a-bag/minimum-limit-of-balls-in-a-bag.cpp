class Solution {
public:
    bool can_divide(vector<int>& nums, int maxOperation, int maxi) {
        int operations = 0;
        for (int i = 0; i < nums.size(); i++) {
            operations += (nums[i] + maxi - 1) / maxi - 1;
        }
        return operations <= maxOperation; 
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;
        int result = high;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (can_divide(nums, maxOperations, mid)) {
                high = mid;
                result = high;
            } else {
                low = mid + 1;
            }
        }
        return result;
    }
};
