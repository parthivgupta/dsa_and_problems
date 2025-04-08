class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        while(true) {
            unordered_set<int> uniques(nums.begin(), nums.end());

            if(uniques.size() == nums.size()) break;

            if(nums.size() > 3) {
                nums.erase(nums.begin(), nums.begin() + 3);
            } else {
                nums.clear();
            }
            operations++;
        }
        return operations;
    }
};