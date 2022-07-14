class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        long long start = 0, end = 0, ans = 0;
        long long sum = 0;
        while(end < arr.size()){
            sum += arr[end];
            
            while(arr[end]*(end-start+1) - sum > k && start <= end)
                sum -= arr[start++];
            
            ans = max(ans, end-start+1);
            end++;
        }
        return ans;
    }
};
/*
T(n) = n*logn
S(n) = O(n)
*/