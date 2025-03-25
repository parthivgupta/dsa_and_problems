class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int first = -1;
        int last = -1;
        // for first occurrence
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) {
                first = mid;
                right = mid - 1;
            } else if(arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        left = 0;
        right = n -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] == target) {
                last = mid;
                left = mid + 1;
            } else if(arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return {first, last};

    }
};