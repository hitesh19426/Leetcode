class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size(), n = nums2.size();
        int low = 0, high = nums1.size(), target = (m+n+1)/2;
        while(low <= high){
            int mid = (low+high)/2;
            int cut1 = mid, cut2 = target - cut1;
            
            if(cut1-1>=0 && cut2 < n && nums1[cut1-1] > nums2[cut2]){
                high = mid-1;
            }
            else if(cut2-1>=0 && cut1 < m && nums2[cut2-1] > nums1[cut1]){
                low = mid+1;
            }
            else{
                int leftMax = -1, rightMin = -1;
                if(cut1-1 < 0)
                    leftMax = nums2[cut2-1];
                else if(cut2-1 < 0)
                    leftMax = nums1[cut1-1];
                else
                    leftMax = max(nums1[cut1-1], nums2[cut2-1]);
                
                if((m+n)&1)
                    return leftMax;
                
                if(cut1 >= m)
                    rightMin = nums2[cut2];
                else if(cut2 >= n)
                    rightMin = nums1[cut1];
                else
                    rightMin = min(nums1[cut1], nums2[cut2]);
                
                return (leftMax+rightMin)/2.0;
            }
        }
        
        return -1;
    }
};

/*
TC(m, n) = log(min(m, n))
SC(m, n) = O(1)
*/

/*
0 ... cut1-1     cut1 .. m-1
0 ... cut2-1     cut2 .. n-1
*/