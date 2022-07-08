class Solution {
    bool check(vector<int>& arr, int divisor, int threshold){
        int sum = 0;
        for(int x: arr)
            sum += x/divisor + (x%divisor != 0);
        return sum <= threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end())+1, ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(nums, mid, threshold))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};