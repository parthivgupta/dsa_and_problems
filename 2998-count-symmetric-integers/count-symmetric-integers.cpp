class Solution {
public:
    bool isSymmetry(const string& s) {
        int len = s.size();
        if (len % 2 != 0) return false;

        int mid = len / 2, sum1 = 0, sum2 = 0;
        for (int i = 0; i < mid; ++i) {
            sum1 += s[i] - '0';
            sum2 += s[i + mid] - '0';
        }
        return sum1 == sum2;
    }

    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; ++i) {
            int len = (int)log10(i) + 1;
            if (len % 2 == 0) {
                string s = to_string(i);
                if (isSymmetry(s)) cnt++;
            }
        }
        return cnt;
    }
};
