class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return {};
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            int low = i+1, high = nums.size()-1, target = -nums[i];
            while(low < high){
                if(nums[low] + nums[high] < target){
                    low++;
                }else if(nums[low] + nums[high] > target){
                    high--;
                } else{
                    ans.push_back({nums[i], nums[low], nums[high]});
                    while(low < high && nums[low] == ans.back()[1])
                        low++;
                    while(low < high && nums[high] == ans.back()[2])
                        high--;
                }
            }
            
            while(i+1<nums.size() && nums[i] == nums[i+1])
                i++;
        }
        
        return ans;
    }
};