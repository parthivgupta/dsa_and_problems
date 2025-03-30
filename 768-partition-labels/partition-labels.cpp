class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26, -1);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a'] = i; 
        }
        vector<int> result;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, freq[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return result;
    }
};