class Solution {
public:
    bool isSymmetry(string s) {
        if(s.size() % 2 == 1) return false;
        int half = 0;

        for(int i = 0; i < s.size() / 2; i++) {
            int a = s[i] - '0';
            half += a; 
        }
        int secondHalf = 0;
        for(int i = s.size() / 2; i < s.size(); i++) {
            int a = s[i] - '0';
            secondHalf += a; 
        }
        return half == secondHalf;

    }

    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low; i <= high; i++) {
            string a = to_string(i);
            if(isSymmetry(a)) cnt++;
        }
        return cnt;
    }
};