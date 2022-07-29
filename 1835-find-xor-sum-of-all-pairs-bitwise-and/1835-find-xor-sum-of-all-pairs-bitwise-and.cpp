class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xora = 0, xorb = 0;
        for(int &x: arr1)
            xora ^= x;
        for(int &x: arr2)
            xorb ^= x;
        return xora&xorb;
    }
};
/*
T(N) = O(32*N)
S(N) = O(32)
*/