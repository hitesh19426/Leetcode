class Solution {
    bool check(vector<int>& arr, int mid, int maxOp){
        int count = 0;
        for(int x: arr){
            count += x/mid + (x%mid != 0) - 1;
        }
        return count <= maxOp;
    }
public:
    int minimumSize(vector<int>& nums, int maxOp) {
        int low = 1, high = *max_element(nums.begin(), nums.end()), ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(nums, mid, maxOp))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};