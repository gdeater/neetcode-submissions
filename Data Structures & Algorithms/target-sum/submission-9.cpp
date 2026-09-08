class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int all = 0;
        for(int i : nums){
            all += i;
        }
        if (abs(target) > all || (all + target) % 2 != 0) return 0;
        int sumP = (all + target) / 2;
        vector<vector<int>> dp(n + 1,vector<int>(sumP + 1,0));
        dp[0][0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j <= sumP;j++){
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]){
                    dp[i][j] += dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sumP];
    }
};