class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size(), half = (m+n+1)/2;
        if(m > n)
            return findMedianSortedArrays(B, A);
        
        bool isOdd = ((m+n)&1);
        int low = 0, high = m;
        while(low <= high){
            int mid = low + (high-low)/2;
            int i = mid, j = half-i;
            if(j>0 && i<m && B[j-1] > A[i]){
                low = mid+1;
            }
            else if(i>0 && j<n && A[i-1] > B[j] ){
                high = mid-1;
            }
            else{
                double leftMax, rightMin;
                
                leftMax = (i==0 ? B[j-1] : (j==0 ? A[i-1] : max(A[i-1], B[j-1])));
                if(isOdd)
                    return leftMax;
                
                rightMin = (i==m ? B[j] : (j==n ? A[i] : min(A[i], B[j]) ));
                return (leftMax + rightMin)/2.0;
            }
        }
        
        return -1;
    }
};