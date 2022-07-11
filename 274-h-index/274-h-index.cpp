class Solution {
    int check(vector<int>& arr, int h){
        int count = 0;
        for(int x: arr){
            if(x >= h)
                count++;
        }
        return count >= h;
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