class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        for (int c = 0; c < n; c++)
            dp[0][c] = points[0][c];

        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                long long best = LLONG_MIN;
                for (int cPrev = 0; cPrev < n; cPrev++) {
                    best = max(best, dp[r-1][cPrev] - abs(c - cPrev));
                }
                dp[r][c] = points[r][c] + best;
            }
        }

        long long ans = LLONG_MIN;
        for (int c = 0; c < n; c++)
            ans = max(ans, dp[m-1][c]);

        return ans;
    }
};