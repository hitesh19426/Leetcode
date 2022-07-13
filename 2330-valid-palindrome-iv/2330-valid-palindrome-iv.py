class Solution:
    def makePalindrome(self, s: str) -> bool:
        low, high, count = 0, len(s)-1, 0;
        while(low < high):
            if(s[low] != s[high]):
                count+=1
            if(count > 2):
                return False
            low, high = low+1, high-1
        return True