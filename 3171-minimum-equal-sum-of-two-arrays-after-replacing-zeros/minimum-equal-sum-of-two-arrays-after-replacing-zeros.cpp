class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, zero1 = 0;
        for (int x : nums1) {
            sum1 += x;
            if (x == 0) {
                zero1++;
            }
        }

        long long sum2 = 0, zero2 = 0;
        for (int x : nums2) {
            sum2 += x;
            if (x == 0) {
                zero2++;
            }
        }

        if (zero1 == 0 && zero2 == 0) {
            return sum1 == sum2 ? sum1 : -1;
        }

        if (zero1 == 0) {
            if (sum1 < sum2 + zero2) {
                return -1;
            }
            return sum1;
        }
        if (zero2 == 0) {
            if (sum2 < sum1 + zero1) {
                return -1;
            }
            return sum2;
        }

        return max(sum1 + zero1, sum2 + zero2);
    }
};