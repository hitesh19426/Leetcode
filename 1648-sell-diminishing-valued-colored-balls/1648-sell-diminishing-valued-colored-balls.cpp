class Solution {
    bool check(vector<int>& arr, int mid, int orders){
        long sum = 0ll;
        for(int x: arr){
            if(x <= mid)
                break;
            sum += (x - mid);
        }
        return sum >= orders;
    }
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(), greater<int>());
        int low = 0, high = inventory[0], mod = 1e9+7, above = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(check(inventory, mid, orders))
                low = mid+1;
            else
                above = mid, high = mid-1;
        }
        
        // cout << above << endl;
        long long ans = 0;
        for(int x: inventory){
            if(x <= above)
                break;
            long long first = above+1, times = x-first+1;
            orders -= times;
            ans += ((x + first)*times)/2;
        }
        ans += (orders)*(long long)above;
        
        return (int)(ans%mod);
    }
};