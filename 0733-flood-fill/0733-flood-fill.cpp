class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int newColor, int color){
        int rows = image.size(), cols = image[0].size();
        if(x<0 || y<0 || x>=rows || y>=cols || image[x][y] != color)
            return;
        
        image[x][y] = newColor;
        int dir[] = {1, 0, -1, 0, 1};
        for(int k=0; k<4; k++)
            dfs(image, x+dir[k], y+dir[k+1], newColor, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};