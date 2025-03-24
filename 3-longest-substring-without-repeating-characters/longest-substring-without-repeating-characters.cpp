class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLen = 0;
        int n = s.size();
        vector<int>freq(256, -1);
        while(right < n) {
            if(freq[s[right]] >= left) {
                left = freq[s[right]] + 1;
            }
            freq[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};