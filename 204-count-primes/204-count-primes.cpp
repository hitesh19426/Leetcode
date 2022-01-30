class Solution {
public:
    int countPrimes(int n) {
        if(n<=1)
            return 0;
        
        n--;
        vector<bool> isprime(n+1, true);
        
        isprime[0] = isprime[1] = false;
        int count = 0;
        for(long long i=2; i<=n; i++){
            if(isprime[i]){
                count++;
                for(long long j=i*i; j<=n; j+=i){
                    isprime[j] = false;
                }
            }
        }
        
        return count;
    }
};