class Solution {
public:
    int maxDistance(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int curr_color = arr[i];
            for(int j = 0; j < n; j++ ) {
                int dis = 0;
                if(curr_color != arr[j]) {
                    dis = abs(j - i);
                    ans = max(dis, ans);
                } else dis = 0;
            }
        }
        return ans;
    }
};