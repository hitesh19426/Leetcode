class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        for(int i=0; i<(int)intervals.size(); i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        int i = 0, j = 0, count = 0, ans = 0;
        while(i<(int)start.size()){
            if(start[i] < end[j]){
                count++, i++;
                ans = max(count, ans);
            }
            else{
                count--, j++;
            }
        }
        return ans;
    }
};