class Solution {
    bool check(vector<int>& time, long long mid, long long total){
        long long count = 0;
        for(long long x: time)
            count += mid/x;
        return count >= total;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1,  high = *min_element(time.begin(), time.end())*(long long)totalTrips, ans = -1;
        while(low <= high){
            auto mid = low + (high-low)/2;
            if(check(time, mid, totalTrips))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};