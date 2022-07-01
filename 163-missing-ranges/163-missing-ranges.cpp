class Solution {
    void add(int a, int b, vector<string>& ranges){
        if(b-1-a <= 0)
            return;
        if(a+1 == b-1)
            ranges.push_back(to_string(a+1));
        else
            ranges.push_back(to_string(a+1) + "->" + to_string(b-1));
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        if(nums.empty()){
            add(lower-1, upper+1, ranges);
            return ranges;
        }
        
        add(lower-1, nums[0], ranges);
        for(int i=0; i<(int)nums.size()-1; i++){
            add(nums[i], nums[i+1], ranges);
        }
        add(nums.back(), upper+1, ranges);
        
        return ranges;
    }
};