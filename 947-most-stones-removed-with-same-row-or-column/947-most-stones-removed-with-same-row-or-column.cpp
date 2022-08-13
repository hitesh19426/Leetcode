class Solution {
    void dfs(int src, vector<bool>& vis, vector<vector<int>>& stones){
        vis[src] = true;
        for(int i=0; i<stones.size(); i++){
            if(!vis[i] && (stones[src][0] == stones[i][0] || stones[i][1] == stones[src][1]))
                dfs(i, vis, stones);
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(), count = 0;
        vector<bool> vis(n, false);
        
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, stones);
                count++;
            }
        }
        return stones.size() - count;
    }
};