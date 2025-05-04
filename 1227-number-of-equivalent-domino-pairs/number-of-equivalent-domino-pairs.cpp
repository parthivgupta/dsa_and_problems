class Solution {
public:
    typedef pair<int, int> pii;
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pii, int> mappa;
        int cnt = 0;
        for(vector<int>& d: dominoes){
            pii p = {d[0], d[1]};
            if(p.second < p.first)
                swap(p.first, p.second);
            cnt += mappa[p];
            mappa[p]++;
        }
        return cnt;
    }
};