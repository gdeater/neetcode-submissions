class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int S = 0;
        for (int x : nums) S += x;
        
        if (abs(target) > S) return 0;
        
        int offset = S;
        vector<vector<int>> dp(n + 1, vector<int>(2 * S + 1, 0));
        dp[0][offset] = 1;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2 * S; j++) {
                if (j - nums[i - 1] >= 0)
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                if (j + nums[i - 1] <= 2 * S)
                    dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
        }
        
        int finalIdx = target + offset;
        if (finalIdx < 0 || finalIdx > 2 * S) return 0;
        return dp[n][finalIdx];
    }
};