class Solution {
public:
    bool containsZero(int n) {
        if (n == 0) {
            return true;
        }
        while (n > 0) { 
            if (n % 10 == 0) { 
                return true; 
            }
            n /= 10; 
        }
        return false; 
    }
    
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int a = i;
            int b = n - i;
            if (!containsZero(a) && !containsZero(b)) {
                return {a, b};
            }
        }
        return {};
    }
};