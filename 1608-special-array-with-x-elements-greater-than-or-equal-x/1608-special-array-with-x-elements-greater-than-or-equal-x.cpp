class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int low = 0, high = nums.back();
        while(low <= high){
            int mid = (low+high)/2;
            int count = nums.end() - lower_bound(nums.begin(), nums.end(), mid);
            if(count < mid){
                high = mid-1;
            }else if(count > mid){
                low = mid+1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};