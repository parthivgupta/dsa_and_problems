class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& current, int index) {
        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        solve(nums, ans, current, index + 1);
        current.pop_back();

        solve(nums, ans, current, index + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(nums, ans, current, 0);
        return ans;
    }
};