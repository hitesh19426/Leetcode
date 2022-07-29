class Solution {
public:
    long long minimumDifference(vector<int>& arr) {
        int n = arr.size(), k = n/3;
        priority_queue<int> left(arr.begin(), arr.begin()+k);
        long long left_sum = accumulate(arr.begin(), arr.begin()+k, 0ll);

        long long min_sum[n], max_sum[n];
        min_sum[k-1] = left_sum;
        for(int i=k; i<2*k; i++){
            left.push(arr[i]);
            left_sum += arr[i] - left.top();
            left.pop();
            min_sum[i] = left_sum;
        }
        
        priority_queue<int, vector<int>, greater<int>> right(arr.begin()+2*k, arr.end());
        long long right_sum = accumulate(arr.begin()+2*k, arr.end(), 0ll);
        max_sum[2*k] = right_sum;
        for(int i=2*k-1; i>=k; i--){
            right.push(arr[i]);
            right_sum += arr[i] - right.top();
            right.pop();
            max_sum[i] = right_sum;
        }
        
        long long ans = LLONG_MAX;
        for(int i=k-1; i<2*k; i++)
            ans = min(ans, min_sum[i] - max_sum[i+1]);
        return ans;
    }
};