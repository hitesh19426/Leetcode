class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> score;
        for(auto &row: mat){
            int low = 0, high = row.size()-1, ind = -1;
            while(low <= high){
                int mid = (low+high)/2;
                if(row[mid] == 1)
                    ind = mid, low = mid+1;
                else
                    high = mid-1;
            }
            score.push_back({ind+1, score.size()});
        }
        
        sort(score.begin(), score.end());
        
        vector<int> ans;
        for(int i=0; i<k; i++){
            ans.push_back(score[i].second);
        }
        return ans;
    }
};