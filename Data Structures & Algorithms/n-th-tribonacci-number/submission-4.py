class Solution:
    def tribonacci(self, n: int) -> int:
        memo = {}
        return self.dp(n,memo)
    def dp(self,n,memo):
        if n == 0:
            return 0
        elif n <= 2:
            return 1
        if n not in memo:
            memo[n] = self.dp(n-1,memo) + self.dp(n-2,memo) + self.dp(n-3,memo)
        return memo[n]