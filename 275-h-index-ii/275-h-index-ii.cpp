class Solution {
    int check(vector<int>& arr, int h){
        return arr.end() - lower_bound(arr.begin(), arr.end(), h) >= h;
    }
public:
    int hIndex(vector<int>& citations) {
        int low = 1, high = *max_element(citations.begin(), citations.end()), ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(citations, mid))
                ans = mid, low=mid+1;
            else
                high = mid-1;
        }
        return ans;
    }
};