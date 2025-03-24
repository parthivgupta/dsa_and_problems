class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int count = meetings[0][0] - 1; 
        int lastMeetingEnd = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++) {
            count += max(0, meetings[i][0] - lastMeetingEnd - 1);
            lastMeetingEnd = max(lastMeetingEnd, meetings[i][1]);
        }
        count += max(0, days - lastMeetingEnd);
        return count;
    }
};