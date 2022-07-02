class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int smallerFromLeft[n], smallerFromRight[n];
        
        for(int i=0; i<n; i++){
            int left = i-1;
            while(left >=0 && heights[left] >= heights[i])
                left = smallerFromLeft[left];
            smallerFromLeft[i] = left;
        }
        
        for(int i=n-1; i>=0; i--){
            int right = i+1;
            while(right <n && heights[right] >= heights[i])
                right = smallerFromRight[right];
            smallerFromRight[i] = right;
        }
        
        int res = 0;
        for(int i=0; i<n; i++){
            int width = smallerFromRight[i] - smallerFromLeft[i] - 1;
            res = max(res, width*heights[i]);
        }
        return res;
    }
};