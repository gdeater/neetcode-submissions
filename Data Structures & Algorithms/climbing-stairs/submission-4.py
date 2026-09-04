class Solution:
    def climbStairs(self, n: int) -> int:
        memo = {}
        return self.dp(n,memo)
    def dp(self,n,memo):
        if n <= 2:
            return n
        elif n not in memo:
            memo[n] = self.dp(n-1,memo) + self.dp(n-2,memo)
        return memo[n]