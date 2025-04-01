class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0; // k must be non-negative

        unordered_map<int, int> numCount;
        // Count occurrences of each number
        for (int num : nums) {
            numCount[num]++;
        }

        int count = 0;

        // Find unique k-diff pairs
        for (const auto& entry : numCount) {
            int num = entry.first;
            if (k == 0) {
                // For k = 0, we need to check if the count of the number is greater than 1
                if (entry.second > 1) {
                    count++;
                }
            } else {
                // For k > 0, check if num + k exists in the map
                if (numCount.find(num + k) != numCount.end()) {
                    count++;
                }
            }
        }

        return count;
    }
};
