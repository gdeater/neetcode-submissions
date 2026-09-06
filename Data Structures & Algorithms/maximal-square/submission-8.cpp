class Solution {
    map<vector<int>, int> mp;
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int high = 0;
        for(int i = 0;i < matrix.size();i++){
            for(int j = 0;j < matrix[0].size();j++){
                high = max(high,dfs(matrix,i,j));
            }
        }
        return high * high;
    }
    int dfs(vector<vector<char>> matrix, int x, int y){
        if (matrix[x][y] == '0'){
            return 0;
        }
        if (x == 0 || y == 0){
            return 1;
        }
        if (mp.count({x,y})){
            return mp[{x,y}];
        }
        mp[{x,y}] = min({dfs(matrix,x - 1,y), dfs(matrix,x - 1,y - 1), dfs(matrix,x,y - 1)}) + 1;
        return mp[{x,y}];
    }
};