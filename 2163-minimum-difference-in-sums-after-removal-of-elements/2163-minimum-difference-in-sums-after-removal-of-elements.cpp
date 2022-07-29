class Solution {
public:
    long long minimumDifference(vector<int>& arr) {
        int n = arr.size(), k = n/3;
        
        long long max_sum[n];
        priority_queue<int, vector<int>, greater<int>> right(arr.begin()+2*k, arr.end());
        long long right_sum = accumulate(arr.begin()+2*k, arr.end(), 0ll);
        max_sum[2*k] = right_sum;
        for(int i=2*k-1; i>=k; i--){
            right.push(arr[i]);
            right_sum += arr[i] - right.top();
            right.pop();
            max_sum[i] = right_sum;
        }        
        
        priority_queue<int> left(arr.begin(), arr.begin()+k);
        long long left_sum = accumulate(arr.begin(), arr.begin()+k, 0ll);
        
        long long ans = left_sum - max_sum[k];
        for(int i=k; i<2*k; i++){
            left.push(arr[i]);
            left_sum += arr[i] - left.top();
            left.pop();
            ans = min(ans, left_sum - max_sum[i+1]);
        }
        return ans;
    }
};