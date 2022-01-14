class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = duration, start = -1, end = -1;
        start = timeSeries[0], end = timeSeries[0]+duration-1;
        
        for(int i=1; i<(int)timeSeries.size(); i++){
            int currentStart = timeSeries[i];
            int currentEnd = timeSeries[i]+duration-1;
            if(end < currentStart){
                total += duration;
            }
            else{
                total += currentEnd - end;
            }
            start = currentStart, end = currentEnd;
        }
        
        return total;
        
        
        /*
        Sort intervals wrt start points; -- you only need last inserted interval to determine overlapping or insert into array case.
        if(ans == empty || end point of last ans < current start)
            ans += interval
        else
            ans.back() start = min(ans.back() start, current Start);
            ans.back() end = min(ans.back() end, current end);
        */
    }
};