class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = duration, start = -1, end = -1;
        start = timeSeries[0], end = timeSeries[0]+duration-1;
        
        for(int i=1; i<(int)timeSeries.size(); i++){
            if(end < timeSeries[i] ){
                total += duration;
                start = timeSeries[i], end = timeSeries[i]+duration-1;
            }
            else{
                total += timeSeries[i]+duration-1 - end;
                end = timeSeries[i]+duration-1;
            }
        }
        
        return total;
        
        
        /*
        Sort intervals wrt start points;
        if(ans == empty || end point of last ans < current start)
            ans += interval
        else
            ans.back() start = min(ans.back() start, current Start);
            ans.back() end = min(ans.back() end, current end);
        */
    }
};