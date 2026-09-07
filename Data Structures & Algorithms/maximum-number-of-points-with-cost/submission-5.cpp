class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<vector<long long>> dp(n,vector<long long>(m,0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if (i == 0){
                    dp[i][j] = points[0][j];
                    continue;
                }
                long long best = -1e15;
                for(int jPrev = 0;jPrev < m;jPrev++){
                    best = max(best,dp[i - 1][jPrev] - abs(jPrev - j));
                }
                dp[i][j] = best + points[i][j];
            }
        }
        long long high = -1e15;
        for(int i = 0;i < m;i++){
            high = max(high,dp[n - 1][i]);
        }
        return high;
    }
};