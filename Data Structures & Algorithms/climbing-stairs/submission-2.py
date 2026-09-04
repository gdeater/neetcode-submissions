class Solution:
    def climbStairs(self, n: int) -> int:
        if n <= 1:
            return 1
        elif n == 2:
            return 2
        dp = [1] * n
        for i in range(1,n):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[-1]
