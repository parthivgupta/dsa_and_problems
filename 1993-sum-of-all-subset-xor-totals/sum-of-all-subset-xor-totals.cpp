class Solution {
public:
    void solve(vector<int>&nums, int index, int currentXOR, int &totalSum) {
        if(index == nums.size()) {
            totalSum += currentXOR;
            return;
        }
        solve(nums, index + 1, currentXOR ^ nums[index], totalSum);
        solve(nums, index + 1, currentXOR, totalSum);
    }
    int subsetXORSum(vector<int>& nums) {
        int totalSum = 0;
        solve(nums, 0, 0, totalSum);
        return totalSum;
    }
};