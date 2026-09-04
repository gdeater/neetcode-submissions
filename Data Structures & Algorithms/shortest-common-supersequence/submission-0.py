class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        n = len(str1)
        m = len(str2)
        dp = [["" for _ in range(m + 1)] for _ in range(n + 1)]
        for i in range(n + 1):
            for j in range(m + 1):
                if i == 0 and j == 0:
                    continue
                if i == 0:
                    dp[i][j] = dp[i][j - 1] + str2[j - 1]
                elif j == 0:
                    dp[i][j] = dp[i - 1][j] + str1[i - 1]
                elif str1[i - 1] == str2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + str1[i - 1]
                else:
                    if len(dp[i - 1][j]) < len(dp[i][j - 1]):
                        dp[i][j] = dp[i - 1][j] + str1[i - 1]
                    else:
                        dp[i][j] = dp[i][j - 1] + str2[j - 1];
                
        return dp[n][m]
        