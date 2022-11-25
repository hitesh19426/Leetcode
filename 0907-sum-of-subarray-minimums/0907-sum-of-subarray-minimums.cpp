class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int biggerOnLeft[n], biggerOnRight[n];
        
        for(int i=0; i<arr.size(); i++){
            int left = i-1;
            while(left>=0 && arr[left] >= arr[i])
                left = biggerOnLeft[left];
            biggerOnLeft[i] = left;
        }
        
        for(int i=arr.size()-1; i>=0; i--){
            int right = i+1;
            while(right<arr.size() && arr[right] > arr[i])
                right = biggerOnRight[right];
            biggerOnRight[i] = right;
        }
        
        long long ans = 0, mod = 1e9+7;
        for(int i=0; i<arr.size(); i++){
            ans += (long long)(i-biggerOnLeft[i])*(biggerOnRight[i]-i)*arr[i];
            ans %= mod;
        }
        return ans;
    }
};