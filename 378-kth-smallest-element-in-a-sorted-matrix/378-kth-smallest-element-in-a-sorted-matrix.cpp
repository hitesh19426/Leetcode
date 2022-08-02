class Solution {
    int count(vector<vector<int>>& matrix, int mid){
        int i = 0, j = matrix[0].size()-1, count = 0;
        while(i<matrix.size() && j>=0){
            if(matrix[i][j] <= mid)
                count += j+1, i++;
            else
                j--;
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int low = INT_MAX, high = INT_MIN, median = -1;
        for(auto &row: matrix){
            low = min(low, row[0]);
            high = max(high, row.back());
        }
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(count(matrix, mid) >= k)
                median = mid, high=mid-1;
            else
                low = mid+1;
        }
        return median;
    }
};
/*
T(M, N) = O(log(max - min)*(M+N))
S(M, N) = O(1)
*/