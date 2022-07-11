class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 1,  n = citations.size(), high = n, ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(citations[n-mid] >= mid)
                ans = mid, low=mid+1;
            else
                high = mid-1;
        }
        return ans;
    }
};