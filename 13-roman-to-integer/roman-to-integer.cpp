class Solution {
public:
    int romToInt(char a) {
        if (a == 'I') return 1;
        if (a == 'V') return 5;
        if (a == 'X') return 10;
        if (a == 'L') return 50;
        if (a == 'C') return 100;
        if (a == 'D') return 500;
        if (a == 'M') return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int result = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && romToInt(s[i]) < romToInt(s[i+ 1])) {
                result -= romToInt(s[i]);
            } else {
                result += romToInt(s[i]);
            }
        }
        return result;
    }
};