class Solution {
    bool check(vector<int> &arr, int mid, int k){
        long count = 0;
        for(int x: arr){
            count += x/mid + (x%mid !=0);
            if(count > k)
                return false;
        }
        return true;
    }
public:
    int minimizedMaximum(int n, vector<int>& quan) {
        long low = 1, high = accumulate(quan.begin(), quan.end(), 0l), ans = -1;
        while(low <= high){
            long mid = low + (high-low)/2;
            if(check(quan, mid, n))
                ans = mid, high = mid-1;
            else
                low = mid+1;
        }
        return (int)ans;
    }
};

// FFFF TTTTT