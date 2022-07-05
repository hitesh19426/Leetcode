class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        
        int ans = 0;
        for(auto x: seen){
            if(seen.find(x-1) != seen.end()){
                ans = max(ans, 1);
            }
            else{
                int curr = 1, last  = x;
                while(seen.find(last+1) != seen.end()){
                    curr++, last++;
                }
                ans = max(ans, curr);
            }
        }
        
        return ans;
    }
};