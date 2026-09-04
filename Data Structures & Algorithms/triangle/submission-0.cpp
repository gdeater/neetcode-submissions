class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[triangle.size() - 1].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0] = triangle[0][0];
        for(int i = 1;i < n;i++){
            for(int j = 0;j < m;j++){
                if (j >= triangle[i].size()){
                    break;
                }
                if (j == 0){
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                    continue;
                }
                if (j == triangle[i].size() - 1){
                    dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
                    continue;
                }
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i-1][j - 1]);
            }
        }
        int low = 1e9;
        for(int i : dp[n - 1]){
            low = min(low,i);
        }
        return low;
    }
};