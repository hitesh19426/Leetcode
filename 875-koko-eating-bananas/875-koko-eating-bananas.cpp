class Solution {
public:
    bool check(vector<int>& arr, long long speed, long long h){
        long long hours = 0;
        for(long long banana: arr){
            hours += (long long)ceil((double)banana/speed);
        }
        return hours <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        
        long long low = 1, high = 0, ans = -1;
        for(long long banana: piles)
            high += banana;
        
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(check(piles, mid, h))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        
        return ans;
    }
};