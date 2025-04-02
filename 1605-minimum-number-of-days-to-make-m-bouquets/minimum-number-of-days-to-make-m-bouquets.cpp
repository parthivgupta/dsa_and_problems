class Solution {
public:
    bool isPossible(vector<int>&bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0;
        int noOfB = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                noOfB += cnt / k;
                cnt = 0;
            }
        }
        noOfB += (cnt / k);
        return noOfB >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val = m * 1ll * k * 1ll;
        if(val > n) return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            mini = min(bloomDay[i], mini);
            maxi = max(bloomDay[i], maxi);
        }

        while(mini <= maxi) {
            int mid = mini + (maxi - mini) / 2;
            if(isPossible(bloomDay, mid, m, k)) {
                maxi = mid - 1;
            } else {
                mini = mid + 1;
            }
        }
        return mini;
    }
};