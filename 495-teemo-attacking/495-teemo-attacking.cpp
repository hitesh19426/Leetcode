class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = duration;
        
        for(int i=1; i<(int)timeSeries.size(); i++){
            int currentStart = timeSeries[i], end = timeSeries[i-1]+duration-1;
            
            int overlap = max(0, end - currentStart + 1);
            total += duration - overlap;
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