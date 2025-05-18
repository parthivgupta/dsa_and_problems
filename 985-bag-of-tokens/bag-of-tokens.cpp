class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size(), score = 0, maxScore = 0, l = 0, r = n - 1;
        while (l <= r)
            if (power >= tokens[l])
                power -= tokens[l++], maxScore = max(maxScore, ++score);
            else if (score)
                power += tokens[r--], score--;
            else
                break;
        return maxScore;
    }
};
