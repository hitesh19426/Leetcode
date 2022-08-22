class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<1)
            return false;
        int count = 0, idx = -1;
        for(int i=0; i<31; i++){
            if(n&(1<<i))
                count++, idx = i;
        }
        return count==1 && idx%2==0;
    }
};