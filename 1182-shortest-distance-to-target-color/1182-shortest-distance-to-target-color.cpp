class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> indexes(3, vector<int>());
        for(int i=0; i<colors.size(); i++){
            indexes[colors[i]-1].push_back(i);
        }
        
        vector<int> ans;
        for(auto &query: queries){
            int ind = query[0], color = query[1];
            if(indexes[color-1].empty()){
                ans.push_back(-1);
            }
            else{
                auto itr = lower_bound(indexes[color-1].begin(), indexes[color-1].end(), ind);
                int dist = INT_MAX;
                if(itr != indexes[color-1].end())
                    dist = *itr - ind;
                if(itr != indexes[color-1].begin())
                    dist = min(dist, ind - *(--itr));
                ans.push_back(dist);
            }
        }
        
        return ans;
    }
};