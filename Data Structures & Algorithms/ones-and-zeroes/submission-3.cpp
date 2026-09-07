class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int cnt = strs.size();
        vector<vector<vector<int>>> dp(cnt + 1,vector<vector<int>>(m + 1,vector<int>(n + 1,0)));
        for(int i = 1;i <= cnt;i++){
            int zero = 0;
            int one = 0;
            for(char c : strs[i - 1]){
                if (c == '1'){
                    one += 1;
                } else {
                    zero += 1;
                }
            }
            for(int j = 0;j <= m;j++){
                for(int k = 0;k <= n;k++){
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zero && k >= one){
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zero][k - one] + 1);
                    }
                }
            }
        }
        return dp[cnt][m][n];
    }
};