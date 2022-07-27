class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        power = 0
        for digit in b:
            power = 10*power + digit
        
        ans = 1
        while(power>0):
            if(power%2 == 1):
                ans = (ans*a)%1337
            a = (a*a)%1337
            power //= 2
        return ans