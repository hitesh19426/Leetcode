class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for(int i=1; i<arr.size(); i++)
            arr[i] ^= arr[i-1];
        
        vector<int> ans;
        for(auto &q: queries)
            ans.push_back((q[0] == 0 ? arr[q[1]] : arr[q[1]]^arr[q[0]-1]));
        return ans;
    }
};