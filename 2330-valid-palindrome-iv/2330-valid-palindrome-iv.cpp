class Solution {
public:
    bool makePalindrome(string s) {
        int low = 0, high = s.size()-1, count = 0;
        while(low < high){
            if(s[low] != s[high])
                count++;
            low++, high--;
        }
        return count <= 2;
    }
};