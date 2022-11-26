class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        
        int ans = 0;
        for(int x: arr1){
            auto itr = lower_bound(arr2.begin(), arr2.end(), x-d);
            if(itr == arr2.end() || abs(*itr - x) > d)
                ans++;
        }
        
        return ans;
    }
};