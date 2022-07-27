struct triplet{
    int i, j, sum;
    triplet(int i, int j, int sum) : i(i), j(j), sum(sum) {}
    bool operator<(const triplet& other) const {
        return sum > other.sum;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<triplet, vector<triplet>> pq;
        set<pair<int, int>> vis;
        pq.push({0, 0, nums1[0] + nums2[0]});
        vis.insert({0, 0});
        
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto [i, j, sum] = pq.top();
            pq.pop();
            
            ans.push_back({nums1[i], nums2[j]});
            if(--k == 0)
                return ans;
            
            if(i+1 < nums1.size() && vis.find({i+1, j}) == vis.end()){
                pq.push(triplet(i+1, j, nums1[i+1] + nums2[j]));
                vis.insert({i+1, j});
            }
            if(j+1 < nums2.size() && vis.find({i, j+1}) == vis.end()){
                pq.push(triplet(i, j+1, nums1[i] + nums2[j+1]));
                vis.insert({i, j+1});
            }
        }
        
        return ans;
    }
};