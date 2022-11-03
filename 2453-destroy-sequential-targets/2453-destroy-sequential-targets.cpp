class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, int> count;
        for(int x: nums)
            count[x%space]++;
        
        int maxcount = 0;
        for(auto& [key, value]: count){
            maxcount = max(maxcount, value);
        }
        
        int ans = INT_MAX;
        for(int x: nums){
            if(count[x%space] == maxcount)
                ans = min(ans, x);
        }
        
        return ans;
    }
};