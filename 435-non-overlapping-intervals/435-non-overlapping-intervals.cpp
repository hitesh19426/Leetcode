class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) -> bool {
            return a[1] < b[1];
        });
        
        int count = 0, endPoint = intervals[0][1];
        for(int i=1; i<(int)intervals.size(); i++){
            if(intervals[i][0] >= endPoint){
                endPoint = intervals[i][1];
            }
            else{
                count++;
            }
        }
        return count;
    }
};