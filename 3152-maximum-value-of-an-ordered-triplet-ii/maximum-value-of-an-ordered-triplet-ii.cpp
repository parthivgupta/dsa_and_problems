
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int size = nums.size();
        if (size < 3) return 0;

        vector<long long> maxLeft(size, 0), maxRight(size, 0);
        maxLeft[0] = nums[0];
        for (int i = 1; i < size; i++) {
            maxLeft[i] = max(maxLeft[i - 1], static_cast<long long>(nums[i]));
        }

        maxRight[size - 1] = nums[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i + 1], static_cast<long long>(nums[i]));
        }

        long long maxTripletValue = 0;
        for (int i = 1; i < size - 1; i++) {
            long long leftMax = maxLeft[i - 1];
            long long rightMax = maxRight[i + 1];
            maxTripletValue = max(maxTripletValue, (leftMax - nums[i]) * rightMax);
        }

        return maxTripletValue;
    }
};