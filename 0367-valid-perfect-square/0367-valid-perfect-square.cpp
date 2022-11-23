class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num, candidate = -1;
        while(low <= high){
            auto mid = (low+high)/2;
            if(mid*mid <= (long long)num)
                candidate = mid, low = mid+1;
            else
                high = mid-1;
        }
        
        return candidate*candidate == num;
    }
};