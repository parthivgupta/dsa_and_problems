class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int maxScore = 0;
        
        int left = 0;
        int right = n - 1;
        int score = 0;

        while(left <= right) {
            if(power >= tokens[left]) {
                power -= tokens[left];
                score++;
                maxScore = max(score, maxScore);
                left++;
            }
            else if(score > 0) {
                power += tokens[right];
                score--;
                right--;
            }
            else break;
        
        }
        return maxScore;
    }
};