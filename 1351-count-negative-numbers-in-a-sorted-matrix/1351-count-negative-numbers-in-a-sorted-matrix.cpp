class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i = 0, j = grid[0].size()-1, m = grid.size(), n = grid[0].size(), ans = 0;
        while(i<m && j>=0){
            if(grid[i][j] < 0)
                j--;
            else
                ans += n-1-j, i++;
        }
        ans += n*max(0, m-i);
        return ans;
    }
};