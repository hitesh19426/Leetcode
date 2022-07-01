class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<long long> prev(points[0].begin(), points[0].end());
        
        for(int i=1; i<points.size(); i++){
            vector<long long> left(n), right(n), curr(n);
            for(int j=0; j<n; j++){
                left[j] = (j == 0 ? prev[0] : max(left[j-1]-1, prev[j]));
            }
            for(int j=n-1; j>=0; j--){
                right[j] = (j == n-1 ? prev[j] : max(right[j+1]-1, prev[j]));
            }
            
            for(int j=0; j<n; j++){
                prev[j] = max(left[j], right[j]) + points[i][j];
            }
            
        }
        
        return *max_element(prev.begin(), prev.end());
    }
};