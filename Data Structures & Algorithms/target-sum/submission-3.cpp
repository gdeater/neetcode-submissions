class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int all = 0;
        for(int x : nums){
            all += x;
        }
        if (abs(target) > all || (all + target) % 2 != 0){
            return 0;
        }
        int sumP = (all + target) / 2;
        vector<int> dp(sumP + 1,0);
        dp[0] = 1;
        for(int x : nums){
            for(int j = sumP;j >= x;j--){
                dp[j] += dp[j - x];
            }
        }
        return dp[sumP];
    }
};