class Solution {
public:
    int myAtoi(string s) {
        int index = 0, sign = 1;
        long long result = 0; // Use long long to prevent integer overflow

        // Skip leading whitespace
        while (index < s.size() && s[index] == ' ') index++;

        // Handle sign
        if (index < s.size() && (s[index] == '-' || s[index] == '+')) {
            if (s[index++] == '-') sign = -1;
        }

        // Process digits
        while (index < s.size() && s[index] >= '0' && s[index] <= '9') {
            result = 10 * result + (s[index++] - '0');

            // Check for overflow before applying sign
            if (result > INT_MAX) {
                if (sign == 1) return INT_MAX;
                else return INT_MIN;
            }
        }

        return (int)(result * sign);
    }
};