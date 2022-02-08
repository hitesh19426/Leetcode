class Solution {
public:
    bool check(vector<int>& arr, long long len, long long k){
        int count = 0;
        for(long long piece: arr){
            count += piece/len;
        }
        return count >= k;
    }
    
    int maxLength(vector<int>& ribbons, int k) {
        long long low = 1, high = 0, ans = 0;
        for(int len:ribbons)
            high += len;
        
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(check(ribbons, mid, k))
                ans = mid, low = mid+1;
            else
                high = mid-1;
        }
        
        return ans;
    }
};