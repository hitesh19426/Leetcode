class Solution {
    long long minSum(long long n, long long ind, long long mid){
        // cout << n << " " << ind << " " << mid << endl;
        long long sum = -mid;
        // cout << "sum = " << sum << endl;
        if(mid + ind - n+1 > 0)
            sum += ((n-ind)*(2*mid + ind -n+1))/2;
        else
            sum += (mid*(mid+1))/2 + (n-ind-mid);
        // cout << "sum = " << sum << endl;
            
        if(mid-ind > 0)
            sum += ((ind+1)*(2*mid-ind))/2;
        else
            sum += (mid*(mid+1))/2 + ind+1-mid;
        // cout << "sum = " << sum << endl;
        return sum;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int low = 1, high = maxSum, ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            // cout << "mid = " << mid << endl;
            if(minSum(n, index, mid) <= (long long)maxSum)
                ans = mid, low = mid+1;
            else
                high = mid-1;
            // cout << endl;
        }
        return ans;
    }
};