class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size(), ans = 0, prev = 0;
        // vector<int> left(n);
        
        // left[0] = 0;
        for(int i=1; i<n; i++){
            // left[i] = max(left[i-1]-1, values[i-1]-1);
            prev = max(prev-1, values[i-1]-1);
            ans = max(ans, values[i] + prev);
        }
        
        return ans;
    }
};