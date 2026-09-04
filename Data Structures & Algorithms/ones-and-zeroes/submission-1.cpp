class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int cnt = strs.size();
        vector<vector<vector<int>>> dp(cnt + 1,vector<vector<int>>(m + 1,vector<int>(n + 1,0)));
        for(int i = 1;i <= cnt;i++){
            string s = strs[i - 1];
            int one = 0;
            int zero = 0;
            for(char p : s){
                if (p == '0'){
                    zero++;
                } else {
                    one++;
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