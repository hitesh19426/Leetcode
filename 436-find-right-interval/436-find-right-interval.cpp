class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> starts;
        for(int i=0; i<intervals.size(); i++)
            starts[intervals[i][0]] = i;

        vector<int> ans(intervals.size(), -1);
        for(int i=0; i<intervals.size(); i++){
            auto itr = starts.lower_bound(intervals[i][1]);
            ans[i] = (itr == starts.end() ? -1 : itr->second);
        }
        
        return ans;
    }
};