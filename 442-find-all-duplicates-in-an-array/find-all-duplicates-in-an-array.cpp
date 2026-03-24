class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int>count;
        vector<int>res;
        for(auto i : nums) ++count[i];

        for(auto i : count) {
            if(i.second > 1) res.push_back(i.first);
        }
        return res;
    }
};