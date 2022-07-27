class Solution {
    bool check(vector<int>& arr, int armor, long health){
        health -= max(arr[0]-armor, 0);
        for(int i=1; i<arr.size(); i++){
            health -= arr[i];
        }
        return health>0;
    }
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        sort(damage.begin(), damage.end(), greater<int>());
        
        long low = 0, high = accumulate(damage.begin(), damage.end(), 0ll)+1, ans = -1;
        while(low <= high){
            long mid = (low+high)/2;
            if(check(damage, armor, mid))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};