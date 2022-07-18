class Solution {
    int m, n;
    int numberOfSubarrayWithSumTarget(vector<int>& arr, int target){
        unordered_map<int, int> prefix;
        int count = 0, sum = 0;
        for(int i=0; i<n; i++){
            sum += arr[i];
            if(sum == target)
                count++;
            if(prefix.find(sum - target) != prefix.end())   // sum[i] - sum[j] = target
                count += prefix[sum - target];
            prefix[sum]++;
        }
        return count;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        m = matrix.size(), n = matrix[0].size();
        int count = 0;
        for(int r1=0; r1<m; r1++){
            vector<int> sum(n, 0);
            for(int r2=r1; r2<m; r2++){
                for(int k=0; k<n; k++)
                    sum[k] += matrix[r2][k];
                
                count += numberOfSubarrayWithSumTarget(sum, target);
            }
        }
        
        return count;
    }
};