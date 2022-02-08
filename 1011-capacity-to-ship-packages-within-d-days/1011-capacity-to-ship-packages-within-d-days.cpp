class Solution {
public:
    bool check(vector<int>& arr, int max_weight, int days){
        int sum = 0, day = 1;
        for(int weight: arr){
            if(weight > max_weight)
                return false;
            if(sum + weight <= max_weight)
                sum += weight;
            else
                sum = weight, day++;
        }
        return day <= days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1, high = 0, ans = -1;
        for(int x: weights)
            high += x;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(weights, mid, days))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        
        return ans;
    }
};