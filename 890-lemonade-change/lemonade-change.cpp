class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;
        int n = bills.size();
        for(int bill : bills) {
            if(bill == 5) count5++;
            else if(bill == 10) {
                count10++;
                count5--;
                if(count5 < 0) return false;
            } else if(bill == 20) {
                if(count10 > 0 && count5 > 0) {
                    count10--;
                    count5--;
                } else if(count5 >= 3) count5 -= 3;
                else return false;
            }
        }
        return true;
    }
};