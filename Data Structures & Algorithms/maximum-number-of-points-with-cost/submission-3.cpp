class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int row = points.size();
        int col = points[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if (i == 0){
                    dp[i][j] = points[i][j];
                    continue;
                }
                int best = -1e9;
                for(int jPrev = 0;jPrev < col;jPrev++){
                    best = max(best,dp[i - 1][jPrev] - abs(j - jPrev));
                }
                dp[i][j] = points[i][j] + best;
            }
        }
        int high = -1e9;
        for(int i : dp[row - 1]){
            high = max(i,high);
        }
        return high;
    }
};