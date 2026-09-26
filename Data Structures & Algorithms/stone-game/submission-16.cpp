class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
        for(int i = n - 1;i >= 0;i--){
            for(int j = i;j < n;j++){
                if (i == j){
                    dp[i][j] = piles[i];
                    continue;
                }
                dp[i][j] = max(dp[i + 1][j] + piles[i], dp[i][j - 1] + piles[j]);
            }
        }
        return dp[0][n - 1];
    }
};