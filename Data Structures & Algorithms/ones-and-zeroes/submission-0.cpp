class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int cnt = strs.size();
        vector<vector<vector<int>>> dp(cnt + 1,vector<vector<int>>(m + 1,vector<int>(n + 1,0)));
        for(int i = 1;i <= cnt;i++){
            int one = 0;
            int zero = 0;
            for(char s : strs[i - 1]){
                if (s == '0'){
                    zero++;
                } else {
                    one++;
                }
            }
            for(int o = 0;o <= m;o++){
                for(int j = 0;j <= n;j++){
                    dp[i][o][j] = dp[i - 1][o][j];
                    if (zero <= o && one <= j){
                        dp[i][o][j] = max(dp[i][o][j],dp[i - 1][o - zero][j - one] + 1);
                    }
                }
            }
        }
        return dp[cnt][m][n];
    }
};