class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = accumulate(nums.begin(),nums.end(),0);
        if (abs(target) > S || (S + target) % 2 != 0){
            return 0;
        }
        int sumP = (S + target) / 2;
        vector<int> dp(sumP + 1,0);
        dp[0] = 1;
        for(int x : nums){
            for(int j = sumP; j >= x;j--){
                dp[j] += dp[j - x];
            }
        }
        return dp[sumP];
    }
};