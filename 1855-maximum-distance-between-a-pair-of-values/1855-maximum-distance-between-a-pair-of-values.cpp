class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i=0; i<nums1.size(); i++){
            int low = i, high = nums2.size()-1, ind = i;
            while(low <= high){
                int mid = (low+high)/2;
                if(nums1[i] <= nums2[mid])
                    ind = mid, low = mid+1;
                else
                    high = mid-1;
            }
            
            ans = max(ans, ind - i);
        }
        
        return ans;
    }
};