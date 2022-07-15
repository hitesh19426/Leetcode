class Solution {
    int rangeSum(int l, int r, vector<int>& prefix){
        return prefix[r+1] - prefix[l];
    }
public:
    int waysToSplit(vector<int>& nums) {
        vector<int> prefix{0};
        for(int x: nums)
            prefix.push_back(prefix.back()+x);
        
        int count = 0, mod = 1e9+7;
        for(int i=1, n = nums.size(); i<n-1; i++){
            int left = prefix[i];
            
            int low = i, high = n-2, lowestj = -1, highestj = -1;
            while(low <= high){
                int mid = (low+high)/2;
                if(prefix[mid+1] >= left + prefix[i])
                    lowestj = mid, high = mid-1;
                else
                    low = mid+1;
            }
            
            if(lowestj == -1)
                continue;
            
            low = lowestj, high = n-2, highestj = -1;
            while(low <= high){
                int mid = (low+high)/2;
                if(2*prefix[mid+1] <= prefix[n] + prefix[i])
                    highestj = mid, low = mid+1;
                else
                    high = mid-1;
            }
            if(highestj == -1)
                continue;
            
            count += (highestj - lowestj + 1);
            count %= mod;
        }
        
        return count;
    }
};