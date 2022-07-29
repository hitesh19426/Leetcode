class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix_xor(arr.size()+1, 0);
        for(int i=1; i<=arr.size(); i++)
            prefix_xor[i] ^= prefix_xor[i-1]^arr[i-1];
        
        vector<int> ans;
        for(auto &query: queries){
            int l = query[0], r = query[1];
            ans.push_back(prefix_xor[r+1]^prefix_xor[l]);
        }
        return ans;
    }
};