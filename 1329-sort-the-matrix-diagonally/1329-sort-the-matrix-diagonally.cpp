class Solution {
    int m, n;
    void sortDiagonal(int i, int j, vector<vector<int>>& matrix){
        vector<int> diag;
        int x = i, y = j;
        while(x<m && y<n){
            diag.push_back(matrix[x][y]);
            x++, y++;
        }
        sort(diag.begin(), diag.end());
        int k = 0;
        while(i<m && j<n){
            matrix[i][j] = diag[k++];
            i++, j++;
        }
    }
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        m = mat.size(), n = mat[0].size();
        for(int i=m-2; i>0; i--)
            sortDiagonal(i, 0, mat);
        for(int j=0; j<n; j++)
            sortDiagonal(0, j, mat);
        return mat;
    }
};