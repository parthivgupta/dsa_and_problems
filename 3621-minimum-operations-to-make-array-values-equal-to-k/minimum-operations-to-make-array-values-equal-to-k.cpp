class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int mini = nums[0];
        int n = nums.size();
        if(mini < k) return -1;

        for(int i = 0; i < n; i++) {
            if(nums[i] > k) count++;
            while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return count;
    }
};