class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window;
 
        for (int i = 0; i < nums.size(); i++) {
            long long num = (long long)nums[i];
 
            auto it = window.lower_bound(num - valueDiff);
 
            if (it != window.end() && *it <= num + valueDiff) {
                return true;
            }
 
            window.insert(num);
 
            if (i >= indexDiff) {
                window.erase((long long)nums[i - indexDiff]);
            }
        }
        return false;
    }
};