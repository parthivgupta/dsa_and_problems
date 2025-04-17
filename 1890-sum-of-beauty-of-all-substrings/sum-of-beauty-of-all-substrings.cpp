class Solution {
public:
    int beautySum(string s) {
        int count = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int maxF = 0, minF = INT_MAX;

                for (int k : freq) {
                    if (k > 0) {
                        maxF = max(k, maxF);
                        minF = min(k, minF);
                    }
                }
                if (minF != INT_MAX) {
                    count += maxF - minF;
                }
            }
        }
        return count;
    }
};