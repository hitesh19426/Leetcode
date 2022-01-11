class Solution {
public:
    void dfs(vector<vector<int>>& image,  int i, int j, int origColor, int newColor){
        int row = image.size(), col = image[0].size();
        if(i<0 || j<0 || i>=row || j>= col || image[i][j] != origColor)
            return;
        
        image[i][j] = newColor;
        dfs(image, i-1, j, origColor, newColor);
        dfs(image, i, j-1, origColor, newColor);
        dfs(image, i+1, j, origColor, newColor);
        dfs(image, i, j+1, origColor, newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor != image[sr][sc])
            dfs(image, sr, sc, image[sr][sc], newColor);
        
        return image;
    }
};