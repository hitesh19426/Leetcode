class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        int freq1 = encoded1[0][1], freq2 = encoded2[0][1], i = 0 , j = 0;
        vector<vector<int>> ans;
        while(i<encoded1.size() && j<encoded2.size()){
            int overlap = min(freq1, freq2), val = encoded1[i][0]*encoded2[j][0];
            if(ans.empty() || ans.back()[0] != val)
                ans.push_back({val, overlap});
            else
                ans.back()[1] += overlap;
            
            freq1 -= overlap, freq2 -= overlap;
            if(freq1 == 0)
                i++, freq1 = (i == encoded1.size() ? 0 : encoded1[i][1]);
            if(freq2 == 0)
                j++, freq2 = (j == encoded2.size() ? 0 : encoded2[j][1]);
        }
        
        return ans;
    }
};