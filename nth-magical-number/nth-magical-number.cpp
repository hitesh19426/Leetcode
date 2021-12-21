class Solution {
public:
    int GCD(int a, int b){
        if(b==0)
            return a;
        return GCD(b, a%b);
    }
    
    bool check(long long a, long long b, long long n, long long mid, long long gcd){
        return (mid/a + mid/b - mid/gcd >= n);
    }
    
    int nthMagicalNumber(int n, int a, int b) {
        if(a > b)
            swap(a, b);
        
        int gcd = GCD(a, b), mod = int(1e9+7);
        long long low = 1, high = LLONG_MAX-5, ans = -1, lcm = (a/gcd)*b;
        while(low <= high){
            long long mid = low + (high-low)/2; // mid is target number
            if(check(a, b, n, mid, lcm))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        
        return (int) (ans%mod);
    }
};