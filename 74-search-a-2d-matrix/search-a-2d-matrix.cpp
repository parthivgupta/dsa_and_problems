class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int high = (m * n) - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int curr_element = matrix[mid/n][mid % n];
            if(curr_element == target) return true;
            else if(curr_element > target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};