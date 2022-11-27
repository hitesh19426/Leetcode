class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {};
        for(char c: s)
            count[c]++;
        
        int ans = 0, isOdd = 0;
        for(int i=0; i<128; i++){
            ans += 2*(count[i]/2);
            isOdd |= (count[i]&1);
        }
        ans += isOdd;
        return ans;
    }
};