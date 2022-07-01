class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> left(n), right(n);
        
        for(int i=0; i<n; i++)
            left[i] = (i==0 ? 0 : max(left[i-1]-1, values[i-1]));
        
        int ans = 0;
        for(int i=1; i<n; i++)
            ans = max(ans, values[i] - 1 + left[i]);
        
        return ans;
    }
};