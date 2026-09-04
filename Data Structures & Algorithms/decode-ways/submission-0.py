class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0
        dp = [0] * (len(s) + 1)
        dp[len(s)] = 1

        if s[-1] != "0":
            dp[-1] = 1
        for i in range(len(s) - 1, -1, -1):
            if s[i] == "0":
                dp[i] = 0
            elif i + 1 < len(s) and int(s[i:i+2]) <= 26:
                dp[i] = dp[i+1] + dp[i+2]
            else:
                dp[i] = dp[i+1]
        return dp[0]

            
            
                


        