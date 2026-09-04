class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 1:
            return ["()"]
        res = []
        def back(cur, op, clo):
            if op == n and clo == n:
                res.append(cur)
                return
            if op < n:
                back(cur + "(",op + 1,clo)
            if clo < op:
                back(cur + ")",op,clo + 1)
        
        back("",0,0)
        return res