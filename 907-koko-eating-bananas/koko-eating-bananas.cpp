class Solution {
public:
    long long calcTime(long long a, vector<int>&piles) {
        long long result = 0;
        for(int i = 0; i < piles.size(); i++) {
            result += (piles[i] + a - 1) / a;
        }
        return result;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int miniSpeed = 1;
        int maxSpeed = INT_MIN;
        int ans = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++) {
            maxSpeed = max(piles[i], maxSpeed);
        }
        while(miniSpeed <= maxSpeed) {
            long long mid = miniSpeed + (maxSpeed - miniSpeed ) / 2;
            long long result = calcTime(mid, piles);
            if(result <= h) {
                ans = mid;
                maxSpeed = mid - 1;
            }
            else {
                miniSpeed = mid + 1;
            }
        }      
        return miniSpeed;
    
    }
};