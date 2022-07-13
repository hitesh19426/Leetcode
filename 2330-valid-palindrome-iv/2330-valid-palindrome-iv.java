class Solution {
    public boolean makePalindrome(String s) {
        int low = 0, high = s.length()-1, count = 0;
        while(low < high){
            if(s.charAt(low) != s.charAt(high))
                count++;
            if(count > 2)
                return false;
            low += 1; high -= 1;
        }
        return true;
    }
}