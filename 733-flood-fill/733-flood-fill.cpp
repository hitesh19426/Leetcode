class Solution {
public:
    void dfs(vector<vector<int>>& image,  int i, int j, int row, int col, int origColor){
        if(i<0 || j<0 || i>=row || j>= col || image[i][j] != origColor)
            return;
        
        image[i][j] = -1;
        dfs(image, i-1, j, row, col, origColor);
        dfs(image, i, j-1, row, col, origColor);
        dfs(image, i+1, j, row, col, origColor);
        dfs(image, i, j+1, row, col, origColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image, sr, sc, image.size(), image[0].size(), image[sr][sc]);
        
        for(auto &row: image){
            for(auto& color: row){
                if(color<0) color = newColor; 
            }
        }
        
        return image;
    }
};