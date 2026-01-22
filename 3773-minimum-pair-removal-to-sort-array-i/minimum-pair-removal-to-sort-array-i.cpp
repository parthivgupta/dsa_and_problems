class Solution {
public:

    bool isSorted(vector<int>&nums) {

        int n = nums.size();

        for(int i = 0; i < n - 1; i++) {
            if(nums[i] > nums[i + 1]) return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {

        int counter = 0;

        while(!isSorted(nums)) {
            int n = nums.size();

            int minSum = INT_MAX;

            int index = 0;

            for(int i = 0; i < n - 1; i++) {
                int currSum = nums[i] + nums[i + 1];

                if(currSum < minSum) {
                    minSum = currSum;
                    index = i;
                }
            }

            nums[index] = nums[index] + nums[index + 1];
            nums.erase(nums.begin() + index + 1);

            counter++;
        }

        return counter;

    }
};