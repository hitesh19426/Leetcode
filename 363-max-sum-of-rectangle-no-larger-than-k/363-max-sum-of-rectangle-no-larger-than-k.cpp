class Solution {
    int MaxSumRectangleNoLargerThanK(vector<int>& arr, int k){
        int sum = 0, maxSum = INT_MIN;
        set<int> sums;
        for(int i=0; i<arr.size(); i++){
            sum += arr[i];
            if(sum <= k)
                maxSum = max(maxSum, sum);
            if(sums.lower_bound(sum-k) != sums.end())   // sum - prefix <= k  => prefix >= sum-k
                maxSum = max(maxSum, sum - *sums.lower_bound(sum-k));
            sums.insert(sum);
        }
        return maxSum;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(), maxsum = INT_MIN;
        
        for(int r1=0; r1<m; r1++){
            vector<int> rows(n, 0);
            for(int r2=r1; r2<m; r2++){
                
                for(int i=0; i<n; i++)
                    rows[i] += matrix[r2][i];
                
                maxsum = max(maxsum, MaxSumRectangleNoLargerThanK(rows, k));
            }
        }
        
        return maxsum;
    }
};