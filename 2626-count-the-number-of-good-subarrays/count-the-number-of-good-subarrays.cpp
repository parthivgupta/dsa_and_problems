class Solution {
public:
long long bruteforce(vector<int>& nums, int k) {
        int n = nums.size();
        long long count = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<int, int>mpp;
            long long pairs = 0;
            for(int j = i; j < n; j++) {
                pairs += mpp[nums[j]];
                
                mpp[nums[j]]++;

                if(pairs >= k) count++;
            }
        }
        return count;
    }

    long long optimalSolution(vector<int>&nums, int k) {
        int n = nums.size();

        unordered_map<int, int>mpp;
        long long cnt = 0;
        int left = 0;
        for(int i = 0; i < n; i++) {
            k = k - mpp[nums[i]]++;

            while(k <= 0) k+= --mpp[nums[left++]];
            cnt += left;
        }
        return cnt;
    }
    long long countGood(vector<int>& nums, int k) {
        
        // return bruteforce(nums, k);

        return optimalSolution(nums, k);
    }
};