class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1){
            return {{1}};
        }
        vector<vector<int>> dp(numRows,vector<int>(numRows,0));
        dp[0][0] = 1;
        for(int i = 1;i < numRows;i++){
            for(int j = 0;j < numRows;j++){
                if (j > i){
                    break;
                }
                if (j == 0 || j == i){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
        vector<vector<int>> res = {};
        for(vector<int> line : dp){
            vector<int> temp = {};
            for(int i : line){
                if (i == 0){
                    break;
                }
                temp.push_back(i);
            }
            res.push_back(temp);
        }
        return res;
    }
};