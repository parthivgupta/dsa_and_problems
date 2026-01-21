class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> solution(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            if ((x & 1) == 0) {
                solution[i] = -1;
            } else {
                int trailingOnes = __builtin_ctz(~x);

                solution[i] = x - (1 << (trailingOnes - 1));
            }
        }

        return solution;
    }
};
