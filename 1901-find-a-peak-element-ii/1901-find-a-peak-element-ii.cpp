class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat[0].size(), lowCol = 0, highCol = cols-1;
        while(lowCol <= highCol){    
            int midCol = (lowCol+highCol)/2, maxRowIndex = 0;
            for(int i=0; i<rows; i++){
                if(mat[i][midCol] > mat[maxRowIndex][midCol])
                    maxRowIndex = i;
            }
            
            bool isLeftSmaller = (midCol==0 || mat[maxRowIndex][midCol-1] < mat[maxRowIndex][midCol]);
            bool isRightSmaller = (midCol==cols-1 || mat[maxRowIndex][midCol+1] < mat[maxRowIndex][midCol]);

            if(isLeftSmaller && isRightSmaller)
                return {maxRowIndex, midCol};
            if(isRightSmaller)
                highCol = midCol;
            else
                lowCol = midCol+1;
        }
        
        return {-1, -1};
    }
};

/*

    7 2 3 1 2
    6 5 4 2 1

*/