class Solution {
    long long lcm(long long a, long long b){
        return (a*b)/__gcd(a, b);
    }
public:
    int nthUglyNumber(long long n, long long a, long long b, long long c) {
        long long mini = min({a, b, c}), low = mini, high = n*mini, ans = -1;
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long divisors = mid/a + mid/b + mid/c - (mid)/lcm(a,b) - mid/lcm(b,c) - mid/lcm(c,a) + mid/lcm(a,lcm(b,c));
            if(divisors >= n)
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return ans;
    }
};