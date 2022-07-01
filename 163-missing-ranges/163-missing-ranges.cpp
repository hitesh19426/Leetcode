class Solution {
    void add(int a, int b, vector<string>& ranges){
        if(a > b)
            return;
        if(a == b)
            ranges.push_back(to_string(a));
        else
            ranges.push_back(to_string(a) + "->" + to_string(b));
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        if(nums.empty()){
            add(lower, upper, ranges);
            return ranges;
        }
        
        if(lower != nums[0])
            add(lower, nums[0]-1, ranges);

        for(int i=0; i<(int)nums.size()-1; i++)
            add(nums[i]+1, nums[i+1]-1, ranges);
            
        if(nums.back() != upper)
            add(nums.back()+1, upper, ranges);
        
        return ranges;
    }
};