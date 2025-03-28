class Solution {
public:
    bool canWePlace(vector<int>&position, int dis, int balls) {
        int n = position.size();
        int lastPos = position[0];
        int count = 1;
        
        for(int i = 1; i < n; i++) {
            if(position[i] - lastPos >= dis) {
                count++;
                lastPos = position[i];
            } 
        }
        return count >= balls;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 1;
        int high = position[n - 1] - position[0];
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            
            if(canWePlace(position, mid, m)) {
                low = mid + 1;
                
            } else {
                high = mid -1;
            }
        }
        return high;
    }
};