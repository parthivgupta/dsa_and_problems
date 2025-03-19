class Solution {
public:
    long long findCost(vector<int>& nums, vector<int>& cost, int c) {
        long long result = 0;  // Use long long for large result
        for (int i = 0; i < nums.size(); i++) {
            result += (long long) abs(c - nums[i]) * cost[i];
        }
        return result;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int low = INT_MAX;
        int high = INT_MIN;
        int n = cost.size();
        
        // Find the minimum and maximum values of nums to limit the search space
        for (int i = 0; i < n; i++) {
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }

        long long answer = LLONG_MAX;  // Use LLONG_MAX for better range handling
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long cost1 = findCost(nums, cost, mid);
            long long cost2 = findCost(nums, cost, mid + 1);

            // Update the answer to keep the smallest cost found
            answer = min(answer, cost1);
            answer = min(answer, cost2);

            // Move search range based on which cost is smaller
            if (cost2 > cost1) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};
