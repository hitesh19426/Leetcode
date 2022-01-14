class Solution {
public:
    bool isPalindrome(string &s, int left, int right){
        while(left <= right && s[left] == s[right]){
            left++, right--;
        }
        return (left > right);
    }
    
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left <= right){
            if(s[left] == s[right])
                left++, right--;
            else{
                if(isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1))
                    return true;
                return false;
            }
        }
        return true;
    }
};