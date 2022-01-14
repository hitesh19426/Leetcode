class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, leftMax = 0, rightMax = 0;
        int water = 0;
        while(left<=right){
            if(leftMax < rightMax){
                if(height[left] > leftMax){
                    leftMax = height[left];
                }
                else{
                    water += leftMax - height[left];
                    left++;
                }
            }
            else{
                if(height[right] > rightMax){
                    rightMax = height[right];
                }
                else{
                    water += rightMax - height[right];
                    right--;
                }
            }
        }
        return water;
    }
};