class Solution {
public:
    string reverseWords(string s) {
        // reverse the whole string
        reverse(s.begin(), s.end());
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++) {
                string words = "";
                while(i < n && s[i] != ' ') {
                    words += s[i];
                    i++;
                }
                reverse(words.begin(), words.end());
                if(words.size() > 0) ans += " " + words;

        }
        return ans.substr(1);
    }
};