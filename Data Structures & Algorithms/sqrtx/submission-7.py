class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0
        r = x
        l = 0

        while r>l:
            m = (r+l)//2
            if m**2 <= x:
                l=m+1
            elif m**2 >x:
                r = m-1

        
        if r**2 >x:
            return r-1
        return r
        
        