class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x: nums)
            freq[x]++;
        
        vector<pair<int, int>> arr;
        for(auto [x, f]: freq)
            arr.push_back({x, f});
        
        nth_element(arr.begin(), arr.begin()+k-1, arr.end(), [](auto &a, auto &b) -> bool {
            return a.second > b.second;
        });
        
        vector<int> ans;
        for(int i=0; i<k; i++)
            ans.push_back(arr[i].first);
        return ans;
    }
};