class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid(n, vector<int>(n, 0));
        int rowStart = 0, rowEnd = n-1, colStart = 0, colEnd = n-1, k = 1;
        while(rowStart <= rowEnd || colStart <= colEnd){
            if(colStart <= colEnd){
                for(int i=colStart; i<=colEnd; i++)
                    grid[rowStart][i] = k++;
            }
            
            if(rowStart < rowEnd){
                for(int i=rowStart+1; i<rowEnd; i++)
                    grid[i][colEnd] = k++;
            }
            
            if(colStart < colEnd){
                for(int i=colEnd; i>=colStart; i--)
                    grid[rowEnd][i] = k++;
            }
            
            if(rowStart < rowEnd){
                for(int i=rowEnd-1; i>rowStart; i--)
                    grid[i][colStart] = k++;
            }
            
            rowStart++, rowEnd--, colStart++, colEnd--;
        }
        
        return grid;
    }
};