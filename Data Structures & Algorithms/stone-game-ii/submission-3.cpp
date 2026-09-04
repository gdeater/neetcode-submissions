class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(2,vector<vector<int>>(n + 1,vector<int>(n + 1,0)));
        for(int i = n - 1;i >= 0;i--){
            for(int m = 1;m <= n;m++){
                int total = 0;
                dp[1][i][m] = 0;
                dp[0][i][m] = 1e9;
                for(int x = 1;x <= m * 2;x++){
                    if (i + x > n){
                        break;
                    }
                    total += piles[i + x - 1];
                    dp[1][i][m] = max(dp[1][i][m],total + dp[0][i + x][max(x,m)]);
                    dp[0][i][m] = min(dp[0][i][m],dp[1][i + x][max(x,m)]);
                }
            }
        }
        return dp[1][0][1];
    }
};