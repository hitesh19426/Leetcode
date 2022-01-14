class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) -> bool {
            return a[1] < b[1];
        });
        
        for(int i=0; i<(int)intervals.size()-1; i++){
            if(intervals[i+1][0] < intervals[i][1])
                return false;
        }
        return true;
    }
};