class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xora = accumulate(arr1.begin(), arr1.end(), 0, [](auto &a, auto &b) -> int {return a^b;});
        int xorb = accumulate(arr2.begin(), arr2.end(), 0, [](auto &a, auto &b) -> int {return a^b;});
        
        return xora&xorb;
    }
};
/*
T(N) = O(32*N)
S(N) = O(32)
*/