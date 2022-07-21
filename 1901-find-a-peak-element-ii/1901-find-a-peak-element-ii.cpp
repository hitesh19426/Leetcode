class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = m-1, ans = -1, colmax = 0, mid = 0;
        while(low < high){
            mid = (high+low)/2;        
            
            for(int i=0; i<n; i++){
                if(mat[mid][i] > mat[mid][colmax])
                    colmax = i;
            }
            
            if(mat[mid][colmax] > mat[mid+1][colmax])
                high = mid;
            else if(mat[mid][colmax] < mat[mid+1][colmax])
                low = mid+1;
        }
        
        return {low, colmax};
    }
};