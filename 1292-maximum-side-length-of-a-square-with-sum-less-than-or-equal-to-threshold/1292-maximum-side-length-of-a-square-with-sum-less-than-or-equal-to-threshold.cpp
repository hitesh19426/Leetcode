typedef vector<vector<long long>> vvll;
typedef vector<long long> vll;

class Solution {
    bool check(int m, int n, vvll& prefix, int mid, int threshold){
        for(int x1=0, x2=mid-1; x2<m; x1++, x2++){
            for(int y1=0, y2=mid-1; y2<n; y1++, y2++){
                long long sum = prefix[x2+1][y2+1] - prefix[x1][y2+1] - prefix[x2+1][y1] + prefix[x1][y1];
                if(sum <= threshold)
                    return true;
            }
        }
        return false;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vvll prefix(m+1, vll(n+1, 0));
        
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + mat[i-1][j-1];
            }
        }
        
        int low = 1, high = min(m, n), ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(check(m, n, prefix, mid, threshold))
                ans = mid, low = mid+1;
            else
                high = mid-1;
        }
        return ans;
    }
};