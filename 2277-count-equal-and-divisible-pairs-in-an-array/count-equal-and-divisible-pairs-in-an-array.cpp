class Solution {
public:
    bool isPair(vector<int>& nums, int i, int j, int k) {
        bool isEqual = nums[i] == nums[j];
        bool isDivisible = (i * j) % k == 0;
        return isEqual && isDivisible;
    }

    int countPairs(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPair(nums, i, j, k)) {
                    count++;
                }
            }
        }
        return count;
    }
};
