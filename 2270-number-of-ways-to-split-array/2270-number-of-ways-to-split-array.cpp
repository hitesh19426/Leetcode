class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> prefix{0};
        for(int x: nums)
            prefix.push_back(prefix.back()+x);
        
        int count = 0;
        for(int i=0, n = nums.size(); i<n-1; i++){
            if(prefix[i+1] >= prefix[n] - prefix[i+1])
                count++;
        }
        return count;
    }
};