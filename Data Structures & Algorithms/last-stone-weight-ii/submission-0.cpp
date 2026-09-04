class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int all = 0;
        for(int i : stones){
            all += i;
        }
        int target = all / 2;
        int n = stones.size();
        vector<vector<int>> dp(n + 1,vector<int>(target + 1,0));
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= target;j++){
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1]){
                    dp[i][j] = max(dp[i][j],dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        }
        return all - dp[n][target] * 2;
    }
};